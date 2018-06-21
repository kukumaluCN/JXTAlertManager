//
//  JXTAlertController.h
//  JXTAlertManager
//
//  Created by JXT on 2016/12/22.
//  Copyright © 2016年 JXT. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

#pragma mark - I.JXTAlertController构造

@class JXTAlertController;
/**
 JXTAlertController: alertAction配置链

 @param title 标题
 @return      JXTAlertController对象
 */
typedef JXTAlertController * _Nonnull (^JXTAlertActionTitle)(NSString *title);

/**
 JXTAlertController: alert按钮执行回调

 @param buttonIndex 按钮index(根据添加action的顺序)
 @param action      UIAlertAction对象
 @param alertSelf   本类对象
 */
typedef void (^JXTAlertActionBlock)(NSInteger buttonIndex, UIAlertAction *action, JXTAlertController *alertSelf);


/**
 JXTAlertController 简介：
 
 1.针对系统UIAlertController封装，支持iOS8及以上
 
 2.关于iOS9之后的`preferredAction`属性用法:
 `alertController.preferredAction = alertController.actions[0];`
 效果为将已存在的某个action字体加粗，原cancel样式的加粗字体成为deafult样式，cancel样式的action仍然排列在最下
 总体意义不大，且仅限于`UIAlertControllerStyleAlert`，actionSheet无效，功能略微鸡肋，不再单独封装
 
 3.关于`addTextFieldWithConfigurationHandler:`方法:
 该方法同样仅限于`UIAlertControllerStyleAlert`使用，使用场景较为局限，推荐直接调用，不再针对封装
 
 4.关于自定义按钮字体或者颜色，可以利用kvc间接访问这些私有属性，但是不推荐
 `[alertAction setValue:[UIColor grayColor] forKey:@"titleTextColor"]`
 */
NS_CLASS_AVAILABLE_IOS(8_0) @interface JXTAlertController : UIAlertController


/**
 JXTAlertController: 禁用alert弹出动画，默认执行系统的默认弹出动画
 */
- (void)alertAnimateDisabled;

/**
 JXTAlertController: alert弹出后，可配置的回调
 */
@property (nullable, nonatomic, copy) void (^alertDidShown)(void);

/**
 JXTAlertController: alert关闭后，可配置的回调
 */
@property (nullable, nonatomic, copy) void (^alertDidDismiss)(void);

/**
 JXTAlertController: 设置toast模式展示时间：如果alert未添加任何按钮，将会以toast样式展示，这里设置展示时间，默认1s
 */
@property (nonatomic, assign) NSTimeInterval toastStyleDuration; //deafult jxt_alertShowDurationDefault = 1s


/**
 JXTAlertController: 链式构造alert视图按钮，添加一个alertAction按钮，默认样式，参数为标题

 @return JXTAlertController对象
 */
- (JXTAlertActionTitle)addActionDefaultTitle;

/**
 JXTAlertController: 链式构造alert视图按钮，添加一个alertAction按钮，取消样式，参数为标题(warning:一个alert该样式只能添加一次!!!)

 @return JXTAlertController对象
 */
- (JXTAlertActionTitle)addActionCancelTitle;

/**
 JXTAlertController: 链式构造alert视图按钮，添加一个alertAction按钮，警告样式，参数为标题

 @return JXTAlertController对象
 */
- (JXTAlertActionTitle)addActionDestructiveTitle;  

@end


#pragma mark - II.UIViewController扩展使用JXTAlertController

/**
 JXTAlertController: alert构造块

 @param alertMaker JXTAlertController配置对象
 */
typedef void(^JXTAlertAppearanceProcess)(JXTAlertController *alertMaker);

@interface UIViewController (JXTAlertController)

/**
 JXTAlertController: show-alert(iOS8)

 @param title             title
 @param message           message
 @param appearanceProcess alert配置过程
 @param actionBlock       alert点击响应回调
 */
- (void)jxt_showAlertWithTitle:(nullable NSString *)title
                       message:(nullable NSString *)message
             appearanceProcess:(JXTAlertAppearanceProcess)appearanceProcess
                  actionsBlock:(nullable JXTAlertActionBlock)actionBlock NS_AVAILABLE_IOS(8_0);

/**
 JXTAlertController: show-actionSheet(iOS8)

 @param title             title
 @param message           message
 @param appearanceProcess actionSheet配置过程
 @param actionBlock       actionSheet点击响应回调
 */
- (void)jxt_showActionSheetWithTitle:(nullable NSString *)title
                             message:(nullable NSString *)message
                   appearanceProcess:(JXTAlertAppearanceProcess)appearanceProcess
                        actionsBlock:(nullable JXTAlertActionBlock)actionBlock NS_AVAILABLE_IOS(8_0);

@end

NS_ASSUME_NONNULL_END
