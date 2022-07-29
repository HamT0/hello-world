//
//  PLVImageMessage.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/11/24.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PLVImageUploadState) {
    PLVImageUploadStateReady = 0,
    PLVImageUploadStateUploading,
    PLVImageUploadStateFailed,
    PLVImageUploadStateSuccess
};

typedef NS_ENUM(NSInteger, PLVImageMessageSendState) {
    PLVImageMessageSendStateReady = 0,
    PLVImageMessageSendStateFailed,
    PLVImageMessageSendStateSuccess
};

@interface PLVImageMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, copy) NSString *imageId;

@property (nonatomic, copy) NSString *imageName;

@property (nonatomic, copy) NSString * _Nullable imageUrl;

@property (nonatomic, strong) UIImage * _Nullable image;

@property (nonatomic, assign) CGSize imageSize;

@property (nonatomic, assign) float uploadProgress;

@property (nonatomic, assign) PLVImageUploadState uploadState;

@property (nonatomic, assign) PLVImageMessageSendState sendState;

@property (nonatomic, assign)NSTimeInterval time;

@property (nonatomic, assign) NSTimeInterval playbackTime;
/// 如果值为"extend"表示为：提醒消息
@property (nonatomic, copy) NSString * _Nullable source;

@end

NS_ASSUME_NONNULL_END
