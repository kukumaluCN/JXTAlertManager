//
//  JXTAlertManagerConstant.h
//  JXTAlertManagerDemo
//
//  Created by JXT on 2016/12/22.
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
 *  回调主线程，显示alert必须在主线程执行
 */
static inline void jxt_getSafeMainQueue(_Nonnull dispatch_block_t block)
{
    jxt_dispatch_main_async_safe(block);
}
