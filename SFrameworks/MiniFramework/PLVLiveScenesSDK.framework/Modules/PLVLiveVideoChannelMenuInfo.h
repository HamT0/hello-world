//
//  PLVLiveVideoChannelMenuInfo.h
//  PLVLiveScenesSDK
//
//  Created by zykhbl(zhangyukun@plv.net) on 2018/7/19.
//  Copyright © 2018年 plv.net. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVFoundationSDK/PLVSafeModel.h>

/// tab子菜单信息
@interface PLVLiveVideoChannelMenu : PLVSafeModel

/// 菜单Id
@property (nonatomic, copy, readonly) NSString *menuId;
/// 菜单类型
@property (nonatomic, copy, readonly) NSString *menuType;
/// 菜单名称
@property (nonatomic, copy, readonly) NSString *name;
/// 菜单内容，html文本，有可能为NSNull
@property (nonatomic, copy, readonly) NSString *content;
/// 菜单显示顺序
@property (nonatomic, copy, readonly) NSNumber *ordered;

@end


/// 频道菜单信息
@interface PLVLiveVideoChannelMenuInfo : PLVSafeModel

/// 直播标题
@property (nonatomic, copy, readonly) NSString *name;
/// 主持人头像
@property (nonatomic, copy, readonly) NSString *coverImage;
/// 主持人
@property (nonatomic, copy, readonly) NSString *publisher;
/// 点赞数
@property (nonatomic, copy, readonly) NSNumber *likes;
/// 观看数
@property (nonatomic, copy, readonly) NSNumber *pageView;
/// 直播时间
@property (nonatomic, copy, readonly) NSString *startTime;
/// 直播状态
@property (nonatomic, copy, readonly) NSString *status;
/// 观看状态
@property (nonatomic, copy, readonly) NSString *watchStatus;
/// 直播间封面图url
@property (nonatomic, copy, readonly) NSString *splashImg;
/// 频道菜单列表
@property (nonatomic, strong, readonly) NSArray<PLVLiveVideoChannelMenu*> *channelMenus;

/// 直播场景
@property (nonatomic, strong, readonly) NSString *scene;
/// 是否有回放视频
@property (nonatomic, assign, readonly) BOOL hasPlayback;
/// 回放开关
@property (nonatomic, strong, readonly) NSString *playBackEnabled;
/// 观众举手示意开关，默认为N 关闭
@property (nonatomic, strong, readonly) NSString *viewerSignalEnabled;
/// 奖励观众奖杯开关，默认为N 关闭
@property (nonatomic, strong, readonly) NSString *awardTrophyEnabled;
/// rtc类型
@property (nonatomic, strong, readonly) NSString *rtcType;
/// 是否还有连麦分钟数
@property (nonatomic, assign, readonly) BOOL pureRtcAvailState;
/// 是否无延迟观看
@property (nonatomic, assign, readonly) BOOL watchNoDelay;
/// 无延迟观看开关 (请以 watchNoDelay 属性为准)
@property (nonatomic, assign, readonly) BOOL pureRtcEnabled;
/// 是否快直播观看(注意：和watchNoDelay没有联系)
@property (nonatomic, assign, readonly) BOOL quickLiveEnabled;
/// 是否只订阅第一画面的视频 (若 watchNoDelay 为NO，则此值必为NO)
@property (nonatomic, assign, readonly) BOOL rtcAudioSubEnabled;
/// 是否开启提醒消息功能，默认为N 关闭，开启为Y（开启后，讲师、嘉宾、助教、管理员可使用提醒消息功能）
@property (nonatomic, assign, readonly) BOOL remindEnabled;
/// 频道未开播、回放开关开启、有回放视频、开启聊天重放这四个均满足则为YES，否则为NO
@property (nonatomic, assign, readonly) BOOL chatInputDisable;
/// 并发限制以聊天室在线人数为准开关，YES为开启 ，NO为关闭 (若 chatRobotEnabled 为YES，则此值必为NO)
@property (nonatomic, assign, readonly) BOOL restrictChatEnabled;
/// 最大同时在线人数 ,<=0表示没有限制，>0表示限制的最大人数
@property (nonatomic, copy, readonly) NSNumber *maxViewer;
/// 虚拟人数设置开关，YES为开启 ，NO为关闭
@property (nonatomic, assign, readonly) BOOL chatRobotEnabled;

@end
