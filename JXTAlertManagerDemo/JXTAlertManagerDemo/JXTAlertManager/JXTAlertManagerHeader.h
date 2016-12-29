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
#ifdef NSFoundationVersionNumber_iOS_8_0
    #import "JXTAlertController.h"
#endif

#endif /* JXTAlertManagerHeader_h */
