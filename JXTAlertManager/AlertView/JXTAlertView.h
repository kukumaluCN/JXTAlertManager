//
//  JXTAlertView.h
//  JXTAlertManager
//
//  Created by JXT on 2016/12/20.
//  Copyright © 2016年 JXT. All rights reserved.
//

#import <UIKit/UIKit.h>

#define jxt_dispatch_main_async_safe(block)\
    if ([NSThread isMainThread]) {\
        block();\
    } else {\
        dispatch_async(dispatch_get_main_queue(), block);\
    }
/**
 回调主线程（显示alert必须在主线程执行）

 @param block 执行块
 */
static inline void jxt_getSafeMainQueue(_Nonnull dispatch_block_t block)
{
    jxt_dispatch_main_async_safe(block);
}

/**
 alert按钮执行回调
 
 @param buttonIndex 按钮index
 */
typedef void (^JXTAlertClickBlock)(NSInteger buttonIndex);


// MARK: 1.常规的alert
/**
 *  JXTAlertView: 两个按钮alert
 */
void jxt_showAlertTwoButton(NSString * _Nullable title,
                            NSString * _Nullable message,
                            NSString * _Nullable cancelButtonTitle,
                            JXTAlertClickBlock _Nullable cancelBlock,
                            NSString * _Nullable otherButtonTitle,
                            JXTAlertClickBlock _Nullable otherBlock);
/**
 *  JXTAlertView: 一个按钮alert
 */
void jxt_showAlertOneButton(NSString * _Nullable title,
                            NSString * _Nullable message,
                            NSString * _Nullable cancelButtonTitle,
                            JXTAlertClickBlock _Nullable cancelBlock);
/**
 *  JXTAlertView: 一个固定按钮alert
 */
void jxt_showAlertTitle(NSString * _Nullable title);
/**
 *  JXTAlertView: 一个固定按钮alert
 */
void jxt_showAlertMessage(NSString * _Nullable message);
/**
 *  JXTAlertView: 一个固定按钮alert
 */
void jxt_showAlertTitleMessage(NSString * _Nullable title,
                               NSString * _Nullable message);


// MARK: 2.无按钮toast
/**
 *  JXTAlertView: 无按钮toast，支持自定义关闭回调
 */
void jxt_showToastTitleMessageDismiss(NSString * _Nullable title,
                                      NSString * _Nullable message,
                                      NSTimeInterval duration,
                                      JXTAlertClickBlock _Nullable dismissCompletion);
/**
 *  JXTAlertView: 无按钮toast，支持自定义关闭回调
 */
void jxt_showToastTitleDismiss(NSString * _Nullable title,
                               NSTimeInterval duration,
                               JXTAlertClickBlock _Nullable dismissCompletion);
/**
 *  JXTAlertView: 无按钮toast，支持自定义关闭回调
 */
void jxt_showToastMessageDismiss(NSString * _Nullable message,
                                 NSTimeInterval duration,
                                 JXTAlertClickBlock _Nullable dismissCompletion);
/**
 *  JXTAlertView: 无按钮toast
 */
void jxt_showToastTitle(NSString * _Nullable title,
                        NSTimeInterval duration);
/**
 *  JXTAlertView: 无按钮toast
 */
void jxt_showToastMessage(NSString * _Nullable message,
                          NSTimeInterval duration);


// MARK: 3.文字HUD，代码执行关闭
/**
 *  JXTAlertView: 文字HUD，jxt_dismissHUD()执行关闭
 */
void jxt_showTextHUDTitleMessage(NSString * _Nullable title,
                                 NSString * _Nullable message);
/**
 *  JXTAlertView: 文字HUD，jxt_dismissHUD()执行关闭
 */
void jxt_showTextHUDTitle(NSString * _Nullable title);
/**
 *  JXTAlertView: 文字HUD，jxt_dismissHUD()执行关闭
 */
void jxt_showTextHUDMessage(NSString * _Nullable message);


// MARK: 4.loadHUD，代码执行关闭
/**
 *  JXTAlertView: loadHUD，jxt_dismissHUD()执行关闭
 */
void jxt_showLoadingHUDTitleMessage(NSString * _Nullable title,
                                    NSString * _Nullable message);
/**
 *  JXTAlertView: loadHUD，jxt_dismissHUD()执行关闭
 */
void jxt_showLoadingHUDTitle(NSString * _Nullable title);
/**
 *  JXTAlertView: loadHUD，jxt_dismissHUD()执行关闭
 */
void jxt_showLoadingHUDMessage(NSString * _Nullable message);


// MARK: 5.ProgressHUD，代码执行关闭
/**
 *  JXTAlertView: ProgressHUD，jxt_dismissHUD()执行关闭
 */
void jxt_showProgressHUDTitleMessage(NSString * _Nullable title,
                                     NSString * _Nullable message);
/**
 *  JXTAlertView: ProgressHUD，jxt_dismissHUD()执行关闭
 */
void jxt_showProgressHUDTitle(NSString * _Nullable title);
/**
 *  JXTAlertView: ProgressHUD，jxt_dismissHUD()执行关闭
 */
void jxt_showProgressHUDMessage(NSString * _Nullable message);
/**
 *  JXTAlertView: ProgressHUD，设置进度值
 */
void jxt_setHUDProgress(float progress);


// MARK: 6.HUD公用
/**
 *  JXTAlertView: 设置HUD成功状态
 */
void jxt_setHUDSuccessTitleMessage(NSString * _Nullable title,
                                   NSString * _Nullable message);
/**
 *  JXTAlertView: 设置HUD成功状态
 */
void jxt_setHUDSuccessTitle(NSString * _Nullable title);
/**
 *  JXTAlertView: 设置HUD成功状态
 */
void jxt_setHUDSuccessMessage(NSString * _Nullable message);

/**
 *  JXTAlertView: 设置HUD失败状态
 */
void jxt_setHUDFailTitleMessage(NSString * _Nullable title,
                                NSString * _Nullable message);
/**
 *  JXTAlertView: 设置HUD失败状态
 */
void jxt_setHUDFailTitle(NSString * _Nullable title);
/**
 *  JXTAlertView: 设置HUD失败状态
 */
void jxt_setHUDFailMessage(NSString * _Nullable message);

/**
 *  JXTAlertView: 关闭HUD
 */
void jxt_dismissHUD(void);



/**
 JXTAlertView 简介：
 
 开发调试使用简易alert/HUD工具
 
 部分提供C函数方便使用，所有show方法的C函数均默认回调主线程
 */
@interface JXTAlertView : UIAlertView

/**
 JXTAlertView: 最多支持两个按钮的alert

 @param title             title
 @param message           message
 @param cancelButtonTitle 取消按钮标题
 @param otherButtonTitle  其他按钮标题
 @param cancelBlock       取消按钮回调
 @param otherBlock        其他按钮回调
 */
+ (void)showAlertViewWithTitle:(nullable NSString *)title
                       message:(nullable NSString *)message
             cancelButtonTitle:(nullable NSString *)cancelButtonTitle
              otherButtonTitle:(nullable NSString *)otherButtonTitle
             cancelButtonBlock:(nullable JXTAlertClickBlock)cancelBlock
              otherButtonBlock:(nullable JXTAlertClickBlock)otherBlock;


/**
 JXTAlertView: 不定数量按钮alert

 @param title             title
 @param message           message
 @param cancelButtonTitle 取消按钮标题
 @param buttonIndexBlock  按钮回调
 @param otherButtonTitles 其他按钮标题列表
 */
+ (void)showAlertViewWithTitle:(nullable NSString *)title
                       message:(nullable NSString *)message
             cancelButtonTitle:(nullable NSString *)cancelButtonTitle
              buttonIndexBlock:(nullable JXTAlertClickBlock)buttonIndexBlock
             otherButtonTitles:(nullable NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;


/**
 JXTAlertView: 不带按钮自动消失的toast

 @param title             title
 @param message           message
 @param duration          显示时间
 @param dismissCompletion 关闭后回调
 */
+ (void)showToastViewWithTitle:(nullable NSString *)title
                       message:(nullable NSString *)message
                      duration:(NSTimeInterval)duration
             dismissCompletion:(nullable JXTAlertClickBlock)dismissCompletion;


/**
 JXTAlertView: 文字HUD

 @param title title
 @param message message
 */
+ (void)showTextHUDWithTitle:(nullable NSString *)title
                     message:(nullable NSString *)message;


/**
 JXTAlertView: loadHUD

 @param title title
 @param message message 
 */
+ (void)showLoadingHUDWithTitle:(nullable NSString *)title
                        message:(nullable NSString *)message;


/**
 JXTAlertView: progressHUD

 @param title title
 @param message message
 */
+ (void)showProgressHUDWithTitle:(nullable NSString *)title
                         message:(nullable NSString *)message;
/**
 JXTAlertView: progressHUD，进度条进度值

 @param progress 进度值
 */
+ (void)setHUDProgress:(float)progress;


/**
 JXTAlertView: HUD公用方法，设置成功状态

 @param title   title
 @param message message
 */
+ (void)setHUDSuccessStateWithTitle:(nullable NSString *)title
                            message:(nullable NSString *)message;
/**
 JXTAlertView: HUD公用方法，设置失败状态
 
 @param title   title
 @param message message
 */
+ (void)setHUDFailStateWithTitle:(nullable NSString *)title
                         message:(nullable NSString *)message;
/**
 JXTAlertView: HUD公用方法，关闭HUD
 */
+ (void)dismissHUD;

@end
