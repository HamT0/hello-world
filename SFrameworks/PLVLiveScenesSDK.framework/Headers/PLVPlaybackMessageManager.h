//
//  PLVPlaybackMessageManager.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2022/6/6.
//  Copyright © 2022 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PLVPlaybackMessage;

NS_ASSUME_NONNULL_BEGIN

@protocol PLVPlaybackMessageManagerDelegate;

@interface PLVPlaybackMessageManager : NSObject

#pragma mark 可配置属性

@property (nonatomic, weak) id<PLVPlaybackMessageManagerDelegate> delegate;
/// 预加载消息最小数目，默认200
@property (nonatomic, assign) NSUInteger maxPreloadCount;

#pragma mark 只读属性

/// 频道号
@property (nonatomic, copy, readonly) NSString *channelId;
/// 回放场次id
@property (nonatomic, copy, readonly) NSString *sessionId;

#pragma mark 方法

- (instancetype)initWithChannelId:(NSString *)channelId sessionId:(NSString *)sessionId;

- (NSArray <PLVPlaybackMessage *>*)playbackMessagInPreloadMessagesFrom:(NSTimeInterval)startTime to:(NSTimeInterval)endTime;

- (void)loadMorePlaybackMessagBefore:(NSTimeInterval)playbackTime;

@end

@protocol PLVPlaybackMessageManagerDelegate <NSObject>

- (void)loadMessageInfoSuccess:(BOOL)success playbackMessageManager:(PLVPlaybackMessageManager *)manager;

- (NSTimeInterval)currentPlaybackTimeForPlaybackMessageManager:(PLVPlaybackMessageManager *)manager;

- (void)loadMoreHistoryMessagesSuccess:(NSArray <PLVPlaybackMessage *>*)playbackMessags playbackMessageManager:(PLVPlaybackMessageManager *)manager;

@end

NS_ASSUME_NONNULL_END
