//
//  JXTAlertView.h
//  JXTAlertManager
//
//  Created by JXT on 2016/12/20.
//  Copyright © 2016年 JXT. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "JXTAlertManagerConstant.h"

/**
 *  JXTAlertView简介：
    开发调试使用简易alert/HUD工具
    部分提供C函数方便使用，所有show方法的C函数均默认回调主线程
 */


/**
 alert按钮执行回调
 
 @param buttonIndex 按钮index
 */
typedef void (^JXTAlertClickBlock)(NSInteger buttonIndex);


/**
 *  1.常规的alert
 */
void jxt_showAlertTwoButton(NSString *title, NSString *message, NSString *cancelButtonTitle, JXTAlertClickBlock cancelBlock, NSString *otherButtonTitle, JXTAlertClickBlock otherBlock);
void jxt_showAlertOneButton(NSString *title, NSString *message, NSString *cancelButtonTitle, JXTAlertClickBlock cancelBlock);
void jxt_showAlertTitle(NSString *title);
void jxt_showAlertMessage(NSString *message);
void jxt_showAlertTitleMessage(NSString *title, NSString *message);

/**
 *  2.无按钮toast
 */
void jxt_showToastTitleMessageDismiss(NSString *title, NSString *message, NSTimeInterval duration, JXTAlertClickBlock dismissCompletion);
void jxt_showToastTitleDismiss(NSString *title, NSTimeInterval duration, JXTAlertClickBlock dismissCompletion);
void jxt_showToastMessageDismiss(NSString *message, NSTimeInterval duration, JXTAlertClickBlock dismissCompletion);
void jxt_showToastTitle(NSString *title, NSTimeInterval duration);
void jxt_showToastMessage(NSString *message, NSTimeInterval duration);

/**
 *  3.文字HUD，代码执行关闭
 */
void jxt_showTextHUDTitleMessage(NSString *title, NSString *message);
void jxt_showTextHUDTitle(NSString *title);
void jxt_showTextHUDMessage(NSString *message);

/**
 *  4.loadHUD，代码执行关闭
 */
void jxt_showLoadingHUDTitleMessage(NSString *title, NSString *message);
void jxt_showLoadingHUDTitle(NSString *title);
void jxt_showLoadingHUDMessage(NSString *message);

/**
 *  5.ProgressHUD，代码执行关闭
 */
void jxt_showProgressHUDTitleMessage(NSString *title, NSString *message);
void jxt_showProgressHUDTitle(NSString *title);
void jxt_showProgressHUDMessage(NSString *message);
//设置进度
void jxt_setHUDProgress(float progress);

/**
 *  6.HUD公用
 */
//成功状态
void jxt_setHUDSuccessTitleMessage(NSString *title, NSString *message);
void jxt_setHUDSuccessTitle(NSString *title);
void jxt_setHUDSuccessMessage(NSString *message);
//失败状态
void jxt_setHUDFailTitleMessage(NSString *title, NSString *message);
void jxt_setHUDFailTitle(NSString *title);
void jxt_setHUDFailMessage(NSString *message);
//关闭HUD
void jxt_dismissHUD();


@interface JXTAlertView : UIAlertView

/**
 1.带按钮的alert

 @param title             title
 @param message           message
 @param cancelButtonTitle 取消按钮标题
 @param otherButtonTitle  其他按钮标题
 @param cancelBlock       取消按钮回调
 @param otherBlock        其他按钮回调
 */
+ (void)showAlertViewWithTitle:(NSString *)title
                       message:(NSString *)message
             cancelButtonTitle:(NSString *)cancelButtonTitle
              otherButtonTitle:(NSString *)otherButtonTitle
             cancelButtonBlock:(JXTAlertClickBlock)cancelBlock
              otherButtonBlock:(JXTAlertClickBlock)otherBlock;


/**
 2.不定数量按钮alert

 @param title             title
 @param message           message
 @param cancelButtonTitle 取消按钮标题
 @param buttonIndexBlock  按钮回调
 @param otherButtonTitles 其他按钮标题列表
 */
+ (void)showAlertViewWithTitle:(NSString *)title
                       message:(NSString *)message
             cancelButtonTitle:(NSString *)cancelButtonTitle
              buttonIndexBlock:(JXTAlertClickBlock)buttonIndexBlock
             otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;


/**
 3.不带按钮自动消失的toast

 @param title             title
 @param message           message
 @param duration          显示时间
 @param dismissCompletion 关闭后回调
 */
+ (void)showToastViewWithTitle:(NSString *)title
                       message:(NSString *)message
                      duration:(NSTimeInterval)duration
             dismissCompletion:(JXTAlertClickBlock)dismissCompletion;


/**
 4.文字HUD

 @param title title
 @param message message
 */
+ (void)showTextHUDWithTitle:(NSString *)title message:(NSString *)message;


/**
 5.loadHUD

 @param title title
 @param message message 
 */
+ (void)showLoadingHUDWithTitle:(NSString *)title message:(NSString *)message;


/**
 6.progressHUD

 @param title title
 @param message message
 */
+ (void)showProgressHUDWithTitle:(NSString *)title message:(NSString *)message;
/**
 进度条进度值

 @param progress 进度值
 */
+ (void)setHUDProgress:(float)progress;


/**
 7.HUD公用方法
 */
/**
 设置成功状态

 @param title   title
 @param message message
 */
+ (void)setHUDSuccessStateWithTitle:(NSString *)title message:(NSString *)message;
/**
 设置失败状态
 
 @param title   title
 @param message message
 */
+ (void)setHUDFailStateWithTitle:(NSString *)title message:(NSString *)message;
/**
 关闭HUD
 */
+ (void)dismissHUD;

@end
