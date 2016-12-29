# JXTAlertManager
UIAlertView/UIAlertController便捷调用工具  
基于系统UIAlertView/UIAlertController封装，简化使用  
详细用法参考Demo  
![JXTAlertManager](/Users/JXT/Downloads/JXTAlertManager-3.png)

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
[JXTAlertView showAlertViewWithTitle:@"title" message:@"message" cancelButtonTitle:@"cancel" buttonIndexBlock:^(NSInteger buttonIndex) {
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
jxt_showLoadingHUDTitleMessage(@"indicatorView-HUD", @"message");  
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
	jxt_dismissHUD();
});
```


## JXTAlertController(iOS8)

### 1.alert
```objective-c
[self jxt_showAlertWithTitle:@"title" message:@"message" appearanceProcess:^(JXTAlertController * _Nonnull alertMaker) {
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
[self jxt_showAlertWithTitle:@"title" message:@"message" appearanceProcess:^(JXTAlertController * _Nonnull alertMaker) {
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
