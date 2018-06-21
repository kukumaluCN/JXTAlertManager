//
//  JXTAlertView.m
//  JXTAlertManager
//
//  Created by JXT on 2016/12/20.
//  Copyright © 2016年 JXT. All rights reserved.
//

#import "JXTAlertView.h"

#pragma mark - Private
/**
 *  取消按钮默认标题
 */
static NSString *const JXTCancelButtonTitleDefault = @"确定";
/**
 *  toast默认展示时间，当设置为0时，用该值
 */
static NSTimeInterval const JXTToastShowDurationDefault = 1.0f;
/**
 *  alertView子视图key
 */
static NSString *const JXTAlertViewAccessoryViewKey = @"accessoryView";


#pragma mark - Public
//1.常规alert
void jxt_showAlertTwoButton(NSString *title, NSString *message, NSString *cancelButtonTitle, JXTAlertClickBlock cancelBlock, NSString *otherButtonTitle, JXTAlertClickBlock otherBlock)
{
    jxt_getSafeMainQueue(^{
        [JXTAlertView showAlertViewWithTitle:title message:message cancelButtonTitle:cancelButtonTitle otherButtonTitle:otherButtonTitle cancelButtonBlock:cancelBlock otherButtonBlock:otherBlock];
    });
}
void jxt_showAlertOneButton(NSString *title, NSString *message, NSString *cancelButtonTitle, JXTAlertClickBlock cancelBlock)
{
    jxt_showAlertTwoButton(title, message, cancelButtonTitle, cancelBlock, nil, NULL);
}
void jxt_showAlertTitle(NSString *title)
{
    jxt_showAlertTwoButton(title, nil, JXTCancelButtonTitleDefault, NULL, nil, NULL);
}
void jxt_showAlertMessage(NSString *message)
{
    jxt_showAlertTwoButton(@"", message, JXTCancelButtonTitleDefault, NULL, nil, NULL);
}
void jxt_showAlertTitleMessage(NSString *title, NSString *message)
{
    jxt_showAlertTwoButton(title, message, JXTCancelButtonTitleDefault, NULL, nil, NULL);
}

//2.无按钮toast
void jxt_showToastTitleMessageDismiss(NSString *title, NSString *message, NSTimeInterval duration, JXTAlertClickBlock dismissCompletion)
{
    jxt_getSafeMainQueue(^{
        [JXTAlertView showToastViewWithTitle:title message:message duration:duration dismissCompletion:dismissCompletion];
    });
}
void jxt_showToastTitleDismiss(NSString *title, NSTimeInterval duration, JXTAlertClickBlock dismissCompletion)
{
    jxt_showToastTitleMessageDismiss(title, nil, duration, dismissCompletion);
}
void jxt_showToastMessageDismiss(NSString *message, NSTimeInterval duration, JXTAlertClickBlock dismissCompletion)
{
    jxt_showToastTitleMessageDismiss(@"", message, duration, dismissCompletion);
}
void jxt_showToastTitle(NSString *title, NSTimeInterval duration)
{
    jxt_showToastTitleMessageDismiss(title, nil, duration, NULL);
}
void jxt_showToastMessage(NSString *message, NSTimeInterval duration)
{
    jxt_showToastTitleMessageDismiss(@"", message, duration, NULL);
}

//3.文字HUD
void jxt_showTextHUDTitleMessage(NSString *title, NSString *message)
{
    jxt_getSafeMainQueue(^{
        [JXTAlertView showTextHUDWithTitle:title message:message];
    });
}
void jxt_showTextHUDTitle(NSString *title)
{
    jxt_showTextHUDTitleMessage(title, nil);
}
void jxt_showTextHUDMessage(NSString *message)
{
    jxt_showTextHUDTitleMessage(@"", message);
}

//4.loadHUD
void jxt_showLoadingHUDTitleMessage(NSString *title, NSString *message)
{
    jxt_getSafeMainQueue(^{
        [JXTAlertView showLoadingHUDWithTitle:title message:message];
    });
}
void jxt_showLoadingHUDTitle(NSString *title)
{
    jxt_showLoadingHUDTitleMessage(title, nil);
}
void jxt_showLoadingHUDMessage(NSString *message)
{
    jxt_showLoadingHUDTitleMessage(@"", message);
}

//5.progressHUD
void jxt_showProgressHUDTitleMessage(NSString *title, NSString *message)
{
    jxt_getSafeMainQueue(^{
        [JXTAlertView showProgressHUDWithTitle:title message:message];
    });
}
void jxt_showProgressHUDTitle(NSString *title)
{
    jxt_showProgressHUDTitleMessage(title, nil);
}
void jxt_showProgressHUDMessage(NSString *message)
{
    jxt_showProgressHUDTitleMessage(@"", message);
}
void jxt_setHUDProgress(float progress)
{
    [JXTAlertView setHUDProgress:progress];
}

//6.HUD公用
//成功状态
void jxt_setHUDSuccessTitleMessage(NSString *title, NSString *message)
{
    jxt_getSafeMainQueue(^{
        [JXTAlertView setHUDSuccessStateWithTitle:title message:message];
    });
}
void jxt_setHUDSuccessTitle(NSString *title)
{
    jxt_setHUDSuccessTitleMessage(title, nil);
}
void jxt_setHUDSuccessMessage(NSString *message)
{
    jxt_setHUDSuccessTitleMessage(@"", message);
}
//失败状态
void jxt_setHUDFailTitleMessage(NSString *title, NSString *message)
{
    jxt_getSafeMainQueue(^{
        [JXTAlertView setHUDFailStateWithTitle:title message:message];
    });
}
void jxt_setHUDFailTitle(NSString *title)
{
    jxt_setHUDFailTitleMessage(title, nil);
}
void jxt_setHUDFailMessage(NSString *message)
{
    jxt_setHUDFailTitleMessage(@"", message);
}
//关闭HUD
void jxt_dismissHUD(void)
{
    jxt_getSafeMainQueue(^{
        [JXTAlertView dismissHUD];
    });
}


#pragma mark - define
/**
 *  JXTAlertType
 */
typedef NS_ENUM(NSInteger, JXTAlertType) {
    JXTAlertTypeNormal,
    JXTAlertTypeToast,
    JXTAlertTypeHUD
};

/**
 *  JXTAlertHUDType
 */
typedef NS_ENUM(NSInteger, JXTAlertHUDType) {
    JXTAlertHUDTypeTextOnly,
    JXTAlertHUDTypeLoading,
    JXTAlertHUDTypeProgress
};


@interface JXTAlertView () <UIAlertViewDelegate>
//block
@property (nonatomic, copy) JXTAlertClickBlock buttonClickBlock;
@property (nonatomic, copy) JXTAlertClickBlock completionBlock;
//type
@property (nonatomic, assign) JXTAlertType alertType;
@property (nonatomic, assign) JXTAlertHUDType alertHUDType;
//HUD附件
@property (nonatomic, strong) UIActivityIndicatorView *indicatorView;
@property (nonatomic, strong) UIProgressView *progressView;

- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitle:(NSString *)otherButtonTitle, ... NS_REQUIRES_NIL_TERMINATION;

@end

@implementation JXTAlertView

#pragma mark - Init
- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitle:(NSString *)otherButtonTitle, ...
{
    self = [self initWithTitle:title message:message delegate:self cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitle, nil];
    if (!self) return nil;
    
    return self;
}

#pragma mark - shared
static JXTAlertView *__jxt_commonHUD = nil;
+ (instancetype)sharedCommonHUDWithHUDType:(JXTAlertHUDType)HUDType
{
    if (__jxt_commonHUD == nil)
    {
        __jxt_commonHUD = [[JXTAlertView alloc] initWithTitle:nil message:nil cancelButtonTitle:nil otherButtonTitle:nil];
        //
        __jxt_commonHUD.alertType = JXTAlertTypeHUD;
        __jxt_commonHUD.alertHUDType = HUDType;
        
        switch (HUDType)
        {
            case JXTAlertHUDTypeTextOnly:
                break;
            case JXTAlertHUDTypeLoading:
            {
                //添加指示器
                UIActivityIndicatorView *indicatorView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
                indicatorView.color = [UIColor blackColor];
                [indicatorView startAnimating];
                __jxt_commonHUD.indicatorView = indicatorView;
                //强制添加子视图
                if (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_6_1)
                {
                    [__jxt_commonHUD setValue:indicatorView forKey:JXTAlertViewAccessoryViewKey];
                }
                else
                {
                    [__jxt_commonHUD addSubview:indicatorView];
                }
                break;
            }
            case JXTAlertHUDTypeProgress:
            {
                //添加进度条
                UIProgressView *progressView = [[UIProgressView alloc] initWithProgressViewStyle:UIProgressViewStyleDefault];
                progressView.progressTintColor = [UIColor blackColor];
                progressView.progress = 0.0;
                __jxt_commonHUD.progressView = progressView;
                //强制添加子视图
                if (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_6_1)
                {
                    [__jxt_commonHUD setValue:progressView forKey:JXTAlertViewAccessoryViewKey];
                }
                else
                {
                    [__jxt_commonHUD addSubview:progressView];
                }
                break;
            }
        }
    }
    return __jxt_commonHUD;
}
+ (JXTAlertView *)sharedCommonHUD
{
    return __jxt_commonHUD;
}
+ (void)clearCommonHUD
{
    __jxt_commonHUD = nil;
}

//重写setValue:forUndefinedKey:方法，处理不存在的key赋值，防止崩溃
- (void)setValue:(id)value forUndefinedKey:(NSString *)key
{
    NSLog(@"key: %@ 不存在", key);
}
- (id)valueForUndefinedKey:(NSString *)key
{
    NSLog(@"value: %@ 不存在", key);
    return nil;
}


#pragma mark - Methods
//1.常规alert
+ (void)showAlertViewWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitle:(NSString *)otherButtonTitle cancelButtonBlock:(JXTAlertClickBlock)cancelBlock otherButtonBlock:(JXTAlertClickBlock)otherBlock
{
    if (!(title.length > 0) && message.length > 0) {
        title = @"";
    }
    JXTAlertView *alertView = [[JXTAlertView alloc] initWithTitle:title message:message cancelButtonTitle:cancelButtonTitle otherButtonTitle:otherButtonTitle, nil];
    
    alertView.alertType = JXTAlertTypeNormal;
    
    alertView.buttonClickBlock = ^(NSInteger buttonIndex){
        if (buttonIndex == 0)
        {
            if (cancelBlock) {
                cancelBlock(buttonIndex);
            }
        }
        else if (buttonIndex == 1)
        {
            if (otherBlock) {
                otherBlock(buttonIndex);
            }
        }
    };
    
    [alertView show];
}
//不定按钮
+ (void)showAlertViewWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle buttonIndexBlock:(JXTAlertClickBlock)buttonIndexBlock otherButtonTitles:(NSString *)otherButtonTitles, ...
{
    if (!(title.length > 0) && message.length > 0) {
        title = @"";
    }
    JXTAlertView *alertView = [[JXTAlertView alloc] initWithTitle:title message:message cancelButtonTitle:cancelButtonTitle otherButtonTitle:nil];
    
    alertView.alertType = JXTAlertTypeNormal;
    alertView.buttonClickBlock = buttonIndexBlock;
    
    if (otherButtonTitles)
    {
        va_list args;//定义一个指向个数可变的参数列表指针
        va_start(args, otherButtonTitles);//得到第一个可变参数地址
        for (NSString *arg = otherButtonTitles; arg != nil; arg = va_arg(args, NSString *))
        {
            [alertView addButtonWithTitle:arg];
        }
        va_end(args);//置空指针
    }
    
    [alertView show];
}

//2.无按钮toast
+ (void)showToastViewWithTitle:(NSString *)title message:(NSString *)message duration:(NSTimeInterval)duration dismissCompletion:(JXTAlertClickBlock)dismissCompletion
{
    if (!(title.length > 0) && message.length > 0) {
        title = @"";
    }
    JXTAlertView *toastView = [[JXTAlertView alloc] initWithTitle:title message:message cancelButtonTitle:nil otherButtonTitle:nil];
    
    toastView.alertType = JXTAlertTypeToast;
    
    toastView.completionBlock = ^(NSInteger buttonIndex){
        if (buttonIndex == 0)
        {
            if (dismissCompletion) {
                dismissCompletion(buttonIndex);
            }
        }
    };
    
    [toastView show];
    
    duration = duration > 0 ? duration : JXTToastShowDurationDefault;
    [toastView performSelector:@selector(dismissToastView:) withObject:toastView afterDelay:duration];
}

- (void)dismissToastView:(UIAlertView *)toastView
{
    [toastView dismissWithClickedButtonIndex:0 animated:YES];
}

//3.文字HUD
+ (void)showTextHUDWithTitle:(NSString *)title message:(NSString *)message
{
    if (!(title.length > 0) && message.length > 0) {
        title = @"";
    }
    JXTAlertView *textHUD = [JXTAlertView sharedCommonHUDWithHUDType:JXTAlertHUDTypeTextOnly];
    
    textHUD.title = title;
    textHUD.message = message;
//    textHUD.delegate = nil;
    
    [textHUD show];
}

//4.loadHUD
+ (void)showLoadingHUDWithTitle:(NSString *)title message:(NSString *)message
{
    if (!(title.length > 0) && message.length > 0) {
        title = @"";
    }
    JXTAlertView *loadingHUD = [JXTAlertView sharedCommonHUDWithHUDType:JXTAlertHUDTypeLoading];
    
    loadingHUD.title = title;
    loadingHUD.message = message;
    
    [loadingHUD show];
}

//5.progressHUD
+ (void)showProgressHUDWithTitle:(NSString *)title message:(NSString *)message
{
    if (!(title.length > 0) && message.length > 0) {
        title = @"";
    }
    JXTAlertView *alertHUD = [JXTAlertView sharedCommonHUDWithHUDType:JXTAlertHUDTypeProgress];
    
    alertHUD.title = title;
    alertHUD.message = message;
    
    [alertHUD show];
}
+ (void)setHUDProgress:(float)progress
{
    JXTAlertView *alertHUD = [JXTAlertView sharedCommonHUD];
    [alertHUD.progressView setProgress:progress animated:YES];
    
    if (progress >= 1.0) {
        [alertHUD.progressView setProgress:1];
//        [alertHUD dismissWithClickedButtonIndex:0 animated:YES];
    }
}

//6.HUD公用
+ (void)setHUDSuccessStateWithTitle:(NSString *)title message:(NSString *)message
{
    JXTAlertView *alertHUD = [JXTAlertView sharedCommonHUD];
    alertHUD.title = title;
    alertHUD.message = message;
    
    switch (alertHUD.alertHUDType)
    {
        case JXTAlertHUDTypeTextOnly:
            break;
        case JXTAlertHUDTypeLoading:
        {
            [alertHUD.indicatorView stopAnimating];
            if (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_6_1)
            {
                [alertHUD setValue:nil forKey:JXTAlertViewAccessoryViewKey];
            }
            else
            {
                [alertHUD.indicatorView removeFromSuperview];
            }
            alertHUD.indicatorView = nil;
            break;
        }
        case JXTAlertHUDTypeProgress:
        {
            [alertHUD.progressView setProgress:1 animated:YES];
            break;
        }
    }
}
+ (void)setHUDFailStateWithTitle:(NSString *)title message:(NSString *)message
{
    JXTAlertView *alertHUD = [JXTAlertView sharedCommonHUD];
    alertHUD.title = title;
    alertHUD.message = message;
    
    switch (alertHUD.alertHUDType)
    {
        case JXTAlertHUDTypeTextOnly:
            break;
        case JXTAlertHUDTypeLoading:
        {
            [alertHUD.indicatorView stopAnimating];
            if (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_6_1)
            {
                [alertHUD setValue:nil forKey:JXTAlertViewAccessoryViewKey];
            }
            else
            {
                [alertHUD.indicatorView removeFromSuperview];
            }
            alertHUD.indicatorView = nil;
            break;
        }
        case JXTAlertHUDTypeProgress:
        {
            [alertHUD.progressView setProgress:0 animated:YES];
            break;
        }
    }
}
+ (void)dismissHUD
{
    JXTAlertView *alertHUD = [JXTAlertView sharedCommonHUD];
    switch (alertHUD.alertHUDType)
    {
        case JXTAlertHUDTypeTextOnly:
            break;
        case JXTAlertHUDTypeLoading:
        {
            [alertHUD.indicatorView stopAnimating];
            alertHUD.indicatorView = nil;
            break;
        }
        case JXTAlertHUDTypeProgress:
            break;
    }
    [alertHUD dismissWithClickedButtonIndex:0 animated:YES];
}


#pragma mark - Delegate
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
{
    if (self.buttonClickBlock) {
        self.buttonClickBlock(buttonIndex);
    }
    self.buttonClickBlock = NULL;//解除闭环
}

- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if (self.completionBlock) {
        self.completionBlock(buttonIndex);
    }
    self.completionBlock = NULL;//解除闭环
    
    switch (self.alertType)
    {
        case JXTAlertTypeNormal:
            break;
            
        case JXTAlertTypeToast:
        {
            //清理performSelector，防止意外情况下的内存泄漏
            [NSObject cancelPreviousPerformRequestsWithTarget:alertView selector:@selector(dismissToastView:) object:alertView];
            break;
        }
        case JXTAlertTypeHUD:
        {
            //清理static
            [JXTAlertView clearCommonHUD];
            break;
        }
    }
}

@end
