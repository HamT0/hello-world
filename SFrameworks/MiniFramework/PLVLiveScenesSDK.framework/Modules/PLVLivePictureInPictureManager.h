//
//  PLVLivePictureInPictureManager.h
//  PLVLiveScenesSDK
//
//  Created by junotang on 2022/2/9.
//  Copyright © 2022 PLV. All rights reserved.
//
//  画中画功能管理类

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVLivePictureInPictureRestoreDelegate;

@interface PLVLivePictureInPictureManager : NSObject

#pragma mark - [ 属性 ]

#pragma mark 可配置项

/// 画中画恢复前的用户界面逻辑代理
@property (nonatomic, weak, nullable) id <PLVLivePictureInPictureRestoreDelegate> restoreDelegate;

/// 画中画播放器是否正在播放正片
@property (nonatomic, assign, readonly) BOOL pictureInPicturePlayerPlaying;

/// 画中画小窗是否开启
@property (nonatomic, assign, readonly) BOOL pictureInPictureActive;

#pragma mark - [ 方法 ]

/// 单例方法
+ (instancetype)sharedInstance;

/// 停止画中画
- (void)stopPictureInPicture;

/// 检查是否支持开启画中画，ipad需要在9.0以上版本，iPhone需要在14.0以上版本
- (BOOL)checkPictureInPictureSupported;

@end

#pragma mark - [ 代理方法 ]

/// 画中画恢复代理
@protocol PLVLivePictureInPictureRestoreDelegate <NSObject>

@optional

/// 点击画中画恢复按钮，画中画关闭之前的用户界面恢复实现
/// @param completionHandler completionHandler
- (void)plvPictureInPictureRestoreUserInterfaceForPictureInPictureStopWithCompletionHandler:(void (^)(BOOL restored))completionHandler;

@end

NS_ASSUME_NONNULL_END
