# JXTAlertManager
UIAlertView/UIAlertController便捷调用工具
详细用法参考Demo

## JXTAlertView

### 1.快速调试工具
```objective-c
jxt_showAlertTitle(@"简易调试使用alert，单按钮，标题默认为“确定”");
```

### 2.两个按钮
```objective-c
[JXTAlertView showAlertViewWithTitle:@"title" message:@"message" cancelButtonTitle:@"cancel" otherButtonTitle:@"other" cancelButtonBlock:^(NSInteger buttonIndex) {
	NSLog(@"cancel");
} otherButtonBlock:^(NSInteger buttonIndex) {
	NSLog(@"other");
}];

```

### 3.不定数量按钮
```objective-c
[JXTAlertView showAlertViewWithTitle:@"不定数量按钮alert" message:@"支持按钮点击回调，根据按钮index区分响应，有cancel按钮时，cancel的index默认0，无cancel时，按钮index根据添加顺序计算" cancelButtonTitle:@"cancel" buttonIndexBlock:^(NSInteger buttonIndex) {
                if (buttonIndex == 0) {
                    NSLog(@"cancel");
                }
                else if (buttonIndex == 1) {
                    NSLog(@"按钮1");
                }
                else if (buttonIndex == 2) {
                    NSLog(@"按钮2");
                }
                else if (buttonIndex == 3) {
                    NSLog(@"按钮3");
                }
                else if (buttonIndex == 4) {
                    NSLog(@"按钮4");
                }
                else if (buttonIndex == 5) {
                    NSLog(@"按钮5");
                }
            } otherButtonTitles:@"按钮1", @"按钮2", @"按钮3", @"按钮4", @"按钮5", nil];
```

### 4.HUD
```objective-c
jxt_showLoadingHUDTitleMessage(@"带indicatorView的HUD", @"支持子标题，手动执行关闭，可改变显示状态");  
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                jxt_dismissHUD();
            });
```


## JXTAlertController

### 1.alert
```objective-c
[self jxt_showAlertWithTitle:@"常规alertController-Alert" message:@"基于系统UIAlertController封装，按钮以链式语法模式快捷添加，可根据按钮index区分响应，可根据action区分响应，支持配置弹出、关闭回调，可关闭弹出动画" appearanceProcess:^(JXTAlertController * _Nonnull alertMaker) {
                alertMaker.
                addActionCancelTitle(@"cancel").
                addActionDestructiveTitle(@"按钮1");
            } actionsBlock:^(NSInteger buttonIndex, UIAlertAction * _Nonnull action, JXTAlertController * _Nonnull alertSelf) {
                if (buttonIndex == 0) {
                    NSLog(@"cancel");
                }
                else if (buttonIndex == 1) {
                    NSLog(@"按钮1");
                }
                NSLog(@"%@--%@", action.title, action);
            }];
```

### 2.添加textField
```objective-c
[self jxt_showAlertWithTitle:@"带输入框的alertController-Alert" message:@"点击按钮，控制台打印对应输入框的内容" appearanceProcess:^(JXTAlertController * _Nonnull alertMaker) {
                alertMaker.
                addActionDestructiveTitle(@"获取输入框1").
                addActionDestructiveTitle(@"获取输入框2");
                
                [alertMaker addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
                    textField.placeholder = @"输入框1-请输入";
                }];
                [alertMaker addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
                    textField.placeholder = @"输入框2-请输入";
                }];
            } actionsBlock:^(NSInteger buttonIndex, UIAlertAction * _Nonnull action, JXTAlertController * _Nonnull alertSelf) {
                if (buttonIndex == 0) {
                    UITextField *textField = alertSelf.textFields.firstObject;
                    [self logMsg:textField.text];//不用担心循环引用
                }
                else if (buttonIndex == 1) {
                    UITextField *textField = alertSelf.textFields.lastObject;
                    [self logMsg:textField.text];
                }
            }];
```
