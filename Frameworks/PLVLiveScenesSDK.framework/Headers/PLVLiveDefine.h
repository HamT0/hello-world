//
//  PLVLiveDefine.h
//  PLVLiveScenesSDK
//
//  Created by zykhbl on 2018/7/27.
//  Copyright © 2018年 PLV. All rights reserved.
//

#ifndef PLVLiveDefine_h
#define PLVLiveDefine_h

/// 频道类型
typedef NS_OPTIONS(NSInteger, PLVChannelType) {
    /// 未知类型
    PLVChannelTypeUnknown = 0,
    /// 云课堂
    PLVChannelTypePPT     = 1 << 0,
    /// 普通直播、大班课（两种类型服务端都返回alone，SDK也看作同一类型）
    PLVChannelTypeAlone   = 1 << 1,
    /// 研讨会（暂不支持该类型）
    PLVChannelTypeSeminar = 1 << 2
};

/// 视频类型
typedef NS_ENUM(NSUInteger, PLVChannelVideoType) {
    /// 视频类型为 直播
    PLVChannelVideoType_Live = 0,
    /// 视频类型为 直播回放（注：特指直播结束后的回放，有别于‘点播’）
    PLVChannelVideoType_Playback = 2,
    /// 视频类型为 推流
    PLVChannelVideoType_Streamer = 4
};

/// 频道 直播流状态
typedef NS_ENUM(NSInteger, PLVChannelLiveStreamState) {
    PLVChannelLiveStreamState_Unknown = -1, /// 状态未知
    PLVChannelLiveStreamState_End     = 0,  /// 无直播流
    PLVChannelLiveStreamState_Live    = 1,  /// 直播中
    PLVChannelLiveStreamState_Stop    = 2   /// 直播暂停
};

/// 频道 连麦场景类型
typedef NS_ENUM(NSInteger, PLVChannelLinkMicSceneType) {
    PLVChannelLinkMicSceneType_Unknown = 0, /// 未知
    PLVChannelLinkMicSceneType_Alone_PartRtc = 1, /// 部分RTC (旧版普通直播连麦)
    PLVChannelLinkMicSceneType_Alone_PureRtc = 2, /// 完全RTC (新版普通直播连麦)
    PLVChannelLinkMicSceneType_PPT_PureRtc = 3    /// 完全RTC (云课堂连麦)
};

/// 频道 连麦媒体类型
typedef NS_ENUM(NSInteger, PLVChannelLinkMicMediaType) {
    PLVChannelLinkMicMediaType_Unknown = 0, // 未知类型
    PLVChannelLinkMicMediaType_Audio = 1,   // 音频连麦
    PLVChannelLinkMicMediaType_Video = 2,   // 视频连麦
};

/// 频道 限制类型
typedef NS_ENUM(NSInteger, PLVChannelRestrictState) {
    PLVChannelRestrictState_GetFailed = -2, /// 获取失败
    PLVChannelRestrictState_Unknown = -1,   /// 未知
    PLVChannelRestrictState_NoneRestrict = 0, /// 无限制（允许播放）
    PLVChannelRestrictState_PlayRestrict = 1, /// 播放受限（不可播放）
};

/// 频道 暖场类型
typedef NS_ENUM(NSUInteger, PLVChannelWarmUpType) {
    PLVChannelWarmUpType_None,  /// 无暖场
    PLVChannelWarmUpType_Image, /// 图片类型
    PLVChannelWarmUpType_Video, /// 视频类型
};

/// 频道 跑马灯类型
typedef NS_ENUM(NSUInteger, PLVChannelMarqueeType) {
    PLVChannelMarqueeType_None,  /// 无跑马灯
    PLVChannelMarqueeType_Fixed, /// 固定类型
    PLVChannelMarqueeType_Nick,  /// 登录用户名类型
    PLVChannelMarqueeType_URL,   /// URL自定义类型
};

/// 频道 防录屏水印类型
typedef NS_ENUM(NSUInteger, PLVChannelWatermarkType) {
    PLVChannelWatermarkType_None,  /// 无水印
    PLVChannelWatermarkType_Fixed, /// 固定类型
    PLVChannelWatermarkType_Nick,  /// 登录用户名类型
};

/// 频道 防录屏水印字体大小
typedef NS_ENUM(NSUInteger, PLVChannelWatermarkFontSize) {
    PLVChannelWatermarkFontSize_Small,    /// 小
    PLVChannelWatermarkFontSize_Middle,  /// 中
    PLVChannelWatermarkFontSize_Large   /// 大
};

#endif /* PLVLiveDefine_h */
