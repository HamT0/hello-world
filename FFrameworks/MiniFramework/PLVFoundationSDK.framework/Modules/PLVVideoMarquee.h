//
//  PLVMarqueeView.h
//  PLVCloudClassSDK
//
//  Created by ftao on 2019/3/1.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "PLVMarqueeModel.h"

DEPRECATED_MSG_ATTRIBUTE("please use PLVMarqueeView! it will be removed in next version.")
@interface PLVVideoMarquee : NSObject

@property (nonatomic, strong) PLVMarqueeModel *marqueeModel;

@property (nonatomic, strong, readonly) UIView *displayView;

/**
 便利初始化视频跑马灯

 @param marqueeModel 跑马灯模型
 @return 视频跑马灯
 */
+ (instancetype)videoMarqueeWithMarqueeModel:(PLVMarqueeModel *)marqueeModel;

/**
 加载视频跑马灯

 @param displayView 显示的图层
 */
- (void)loadVideoMarqueeInView:(UIView *)displayView;

/**
 显示跑马灯
 */
- (void)showVideoMarquee;

/**
 隐藏跑马灯
 */
- (void)hideVideoMarquee;

@end
