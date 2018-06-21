//
//  JXTAlertManagerHeader.h
//  JXTAlertManagerDemo
//
//  Created by JXT on 2016/12/22.
//  Copyright © 2016年 JXT. All rights reserved.
//

#ifndef JXTAlertManagerHeader_h
#define JXTAlertManagerHeader_h

#import "JXTAlertView.h"

//以下适配，只做提示用，实际使用，如果要适配iOS7，对应方法还是需要自行适配
//不然的话，可能因为这个宏，导致bug，因为新版xcode编译，对应方法是可以使用的（因为xcode的API存在），但是实际在对应系统上，可能就崩溃了
#ifdef NSFoundationVersionNumber_iOS_8_0
    #import "JXTAlertController.h"
#endif

#endif /* JXTAlertManagerHeader_h */
