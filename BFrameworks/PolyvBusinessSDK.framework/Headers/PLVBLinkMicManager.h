//
//  PLVBLinkMicManager.h
//  PolyvBusinessSDK
//
//  Created by Lincal on 2020/3/20.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PLVBRTCDefine.h"
#import "PLVBRTCVideoViewCanvasModel.h"
#import "PLVBRTCVideoEncoderConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PLVBLinkMicManagerDelegate;

/// RTC管理器
///
/// @note 负责支持 连麦、RTC推流 的功能模块
@interface PLVBLinkMicManager : NSObject

#pragma mark - [ 属性 ]
#pragma mark 可配置项
/// 代理
@property (nonatomic, weak) id <PLVBLinkMicManagerDelegate> delegate;

#pragma mark 数据
/// RTC频道Id (房间Id)
@property (nonatomic, copy, readonly) NSString * channelId;
/// 本地用户的RTCId
@property (nonatomic, copy, readonly) NSString * userLinkMicId;
/// RTC类型
@property (nonatomic, assign, readonly) PLVBLinkMicRTCType rtcType;
/// 当前 本地预览画面的画布模型
///
/// @note 只读，仅可通过 [setupLocalPreviewWithCanvasModel:] 方法进行配置；
///       读取后，对此 currentLocalPreviewCanvasModel 中的属性作修改不会生效；
///       若希望修改 本地预览画面的画布模型 的属性，且生效。请重新调用 [setupLocalPreviewWithCanvasModel:] 方法；
@property (nonatomic, strong, readonly) PLVBRTCVideoViewCanvasModel * currentLocalPreviewCanvasModel;
/// 当前 视频编码配置模型
@property (nonatomic, strong, readonly) PLVBRTCVideoEncoderConfiguration * currentVideoEncoderConfiguration;

#pragma mark 状态
/// 当前 引擎是否已就绪
@property (nonatomic, assign, readonly) BOOL engineIsReady;
/// 当前 rtcToken 是否可用
@property (nonatomic, assign, readonly) BOOL rtcTokenAvailable;
/// 当前 是否已加入rtc频道
@property (nonatomic, assign, readonly) BOOL hadJoinedRTC;
/// 当前 网络状态
@property (nonatomic, assign, readonly) PLVBLinkMicNetworkQuality networkQuality;
/// 当前 RTC频道 连接状态
@property (nonatomic, assign, readonly) PLVBLinkMicConnectionStateType connectionState;
/// 当前 用户角色
@property (nonatomic, assign, readonly) PLVBLinkMicRoleType roleType;
/// 当前 是否正在推流至cdn
@property (nonatomic, assign, readonly) BOOL streamPublishing;

/// 当前 本地视频预览画面 镜像类型
@property (nonatomic, assign, readonly) PLVBRTCVideoMirrorMode localVideoMirrorMode;
/// 当前 本地摄像头 是否前置
@property (nonatomic, assign, readonly) BOOL localCameraFront;
/// 当前 本地闪光灯 是否开启
@property (nonatomic, assign, readonly) BOOL localCameraTorchOpen;
/// 当前 本地摄像头 是否开启
@property (nonatomic, assign, readonly) BOOL localCameraOpen;
/// 当前 本地视频流 是否停止推送
@property (nonatomic, assign, readonly) BOOL localVideoStreamMute;
/// 当前 本地视频流占位图 是否开启
@property (nonatomic, assign, readonly) BOOL localVideoStreamPlaceholderOpen;
/// 当前 本地视频数据采集 是否开启
@property (nonatomic, assign, readonly) BOOL localVideoEnable;

/// 当前 本地麦克风 音量
@property (nonatomic, assign, readonly) CGFloat localMicVolume;
/// 当前 本地麦克风 是否开启
@property (nonatomic, assign, readonly) BOOL localMicOpen;
/// 当前 本地音频数据采集 是否开启
@property (nonatomic, assign, readonly) BOOL localAudioEnable;
/// 当前 本地音频流 是否停止推送
@property (nonatomic, assign, readonly) BOOL localAudioStreamMute;

#pragma mark 流相关
@property (nonatomic, assign, readonly) NSUInteger videoCDNWidth;

@property (nonatomic, assign, readonly) NSUInteger videoCDNHeight;


#pragma mark - [ 方法 ]
/// 创建 RTC管理器
///
/// @note 由外部根据频道信息获取到rtc类型值，并在调用此方法时传入；
///       若传入的rtcType值无效，将创建失败，并返回 nil。
///
/// @param rtcType rtc类型值
+ (instancetype)linkMicManagerWithRTCType:(NSString *)rtcType;

/// 更新 RTC Token
///
/// @note 加入RTC连麦频道前，必须调用此方法更新连麦Token。
///       调用该方法，将立刻收到返回的 int 值，小于0表示更新失败 (失败原因可见打印)，此时不允许加入RTC连麦频道，调用 [joinRtcChannelWithChannelId:] 将失败；等于0表示成功。
///
/// @param linkMicStr 连麦信息字符串
- (int)updateLinkMicTokenWithStr:(NSString *)linkMicStr;

/// 创建 RTC引擎
- (void)createRTCEngine;

/// 销毁 RTC引擎
- (void)destroyRTCEngine;

/// 加入 RTC房间
- (int)joinRtcChannelWithChannelId:(NSString *)channelId userLinkMicId:(NSString *)userLinkMicId;

/// 退出 RTC频道
- (int)leaveRtcChannel;

/// 将某位用户的流渲染于视图中
///
/// @param rtcUserId 用户RTCId
/// @param renderSuperView 承载渲染的父视图
/// @param mediaType 订阅的流的媒体类型 (支持组合)
- (void)subscribeStreamWithRTCUserId:(NSString *)rtcUserId renderOnView:(UIView *)renderSuperView mediaType:(PLVBRTCSubscribeStreamMediaType)mediaType;

- (void)unsubscribeStreamWithRTCUserId:(NSString *)rtcUserId;

- (void)switchSubscribeStreamMediaTypeWithRTCUserId:(NSString *)rtcUserId mediaType:(PLVBRTCSubscribeStreamMediaType)toMediaType;

/// 切换用户角色
- (int)setUserRoleTo:(PLVBLinkMicRoleType)roleType;

#pragma mark 视频管理
/// 配置 视频编码参数
- (void)setupVideoEncoderConfiguration:(PLVBRTCVideoEncoderConfiguration *)videoEncoderConfiguration;

/// 配置本地预览画面
///
/// @note 仅作用于 本地预览画面 的相关属性配置；
///       不自动开始预览，不自动开始推视频流；
- (void)setupLocalPreviewWithCanvasModel:(PLVBRTCVideoViewCanvasModel *)canvasModel;

/// 配置 本地视频预览画面 的镜像类型
///
/// @param mirrorMode 本地视频预览画面的镜像类型 (默认值:PLVBRTCVideoMirrorMode_Auto)
- (int)setupLocalVideoPreviewMirrorMode:(PLVBRTCVideoMirrorMode)mirrorMode;

/// 切换 本地用户 的前后置摄像头
///
/// @param frontCamera 切换为 前置或后置 摄像头 (YES:前置；NO:后置)
- (int)switchLocalUserCamera:(BOOL)frontCamera;

/// 开启或关闭 本地用户 的闪光灯
///
/// @param openCameraTorch 开启或关闭 闪光灯 (YES:开启；NO:关闭)
- (int)openLocalUserCameraTorch:(BOOL)openCameraTorch;

/// 开启或关闭 本地用户 的摄像头
///
/// @note 开启：采集数据、渲染预览、取消停止本地视频流推送；关闭：停止采集数据、停止渲染预览、停止本地视频流推送；
///       将触发RTC房间内其他成员，收到回调；推荐直接使用该方法；
///
/// @param openCamera 开启或关闭 摄像头 (YES:开启；NO:关闭)
- (int)openLocalUserCamera:(BOOL)openCamera;

/// 本地视频流 开启或关闭 占位图
///
/// @param openPlaceholder 开启或关闭 占位图 (YES:开启；NO:关闭)
- (int)localVideoStreamOpenPlaceholder:(BOOL)openPlaceholder;

/// 开启或停止 本地摄像头采集
///
/// @note 开启：摄像头采集数据；停止：停止摄像头采集数据
///       该方法 在部分RTC类型下 调用无效；推荐直接使用 [openLocalUserCamera:] 方法
///
/// @param enabled 开启或停止 (YES:开启；NO:停止)
- (int)enableLocalVideo:(BOOL)enabled;

/// 开启或停止 本地摄像头预览
///
/// @note 开启：渲染预览；停止：停止渲染预览
///       该方法 在部分RTC类型下 调用无效；推荐直接使用 [openLocalUserCamera:] 方法
///
/// @param start 开启或停止 (YES:开启；NO:停止)
- (int)startLocalPreview:(BOOL)start;

/// 停止或取消停止 本地视频流 推送
///
/// @note 将触发RTC房间内其 他成员，收到回调；
///       推荐直接使用 [openLocalUserCamera:] 方法
///
/// @param mute 停止或取消停止 本地视频流 (YES:停止；NO:取消停止)
- (int)muteLocalVideoStream:(BOOL)mute;

#pragma mark 音频管理
/// 改变 本地麦克风 录入音量
///
/// @note 数值 0 即静音；即使0也不会触发 [muteLocalAudioStream:]
///
/// @param micVolume 麦克风音量值 (0~100)
- (int)changeLocalMicVolume:(CGFloat)micVolume;

/// 开启或关闭 本地用户 的麦克风
///
/// @note 开启：采集数据、取消停止本地音频流推送；关闭：停止采集数据、停止本地音频流推送；
///       将触发RTC房间内其他成员，收到回调；推荐直接使用该方法；
///
/// @param openMic 开启或关闭 麦克风 (YES:开启；NO:关闭)
- (int)openLocalUserMic:(BOOL)openMic;

/// 开启或停止 本地麦克风采集
///
/// @note 开启：麦克风采集数据；停止：停止麦克风采集数据
///       该方法 在部分RTC类型下 调用无效；推荐直接使用 [openLocalUserMic:] 方法；
///
/// @param enabled 开启或停止 (YES:开启；NO:停止)
- (int)enableLocalAudio:(BOOL)enabled;

/// 停止或取消停止 本地音频流 推送
///
/// @note 将触发RTC房间内其他成员，收到回调；
///       该方法 在部分RTC类型下 调用无效；推荐直接使用 [openLocalUserMic:] 方法；
///
/// @param mute 停止或取消停止 本地音频流 (YES:停止；NO:取消停止)
- (int)muteLocalAudioStream:(BOOL)mute;

#pragma mark 流管理
/// 开始推本地摄像头画面流
- (void)startPublishLocalStream;
/// 停止推本地摄像头画面流
- (void)stopPublishLocalStream;

#pragma mark 转推相关
/// 添加推流地址
- (int)addPublishStreamUrl:(NSString *)streamUrl transcodingEnabled:(BOOL)transcodingEnabled;
/// 移除推流地址
- (int)removePublishStreamUrl:(NSString *)streamUrl;
/// 配置推流转码参数
- (void)setupLiveTranscoding;
/// 配置混流参数
- (int)setupLiveTranscodingUser;
/// 配置混流额外信息
- (int)setupLiveTranscodingExtraInfo:(NSString *)extroInfo;
/// 配置推流占位图
- (int)setupLiveBackgroundImage;

@end

#pragma mark - [ 代理方法 ]
/// PLVBLinkMicManager 的 Delegate
@protocol PLVBLinkMicManagerDelegate <NSObject>

@optional

#pragma mark 本地用户(自己) 事件回调
/// 本地用户 加入RTC频道
///
/// @param manager 连麦管理器
/// @param channelId 加入频道ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager joinRTCChannelComplete:(NSString * _Nonnull)channelId uid:(NSString *)uid;

/// 本地用户 退出RTC频道
///
/// @param manager 连麦管理器
/// @param channelId 退出频道ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager leaveRTCChannelComplete:(NSString * _Nonnull)channelId;

/// 本地用户 连麦发生错误（若自动退出RTC频道，则会触发 [leaveRTCChannelComplete:] 回调）
///
/// @param manager 连麦管理器
/// @param error 错误对象
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didOccurError:(NSError *)error;

/// 本地RTC连接状态改变
///
/// @param manager 连麦管理器
/// @param connectionState 当前rtc连接状态
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager rtcConnectionStateDidChanged:(PLVBLinkMicConnectionStateType)connectionState;

/// 本地用户 连麦Token过期
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerTokenExpires:(PLVBLinkMicManager * _Nonnull)manager;

/// 适合配置 本地硬件默认值 的时机回调
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerCanSetupLocalHardwareDefaultState:(PLVBLinkMicManager * _Nonnull)manager;

#pragma mark 本地设备事件回调
/// 本地用户 ‘网络状态’ 发生改变回调
///
/// @param manager 连麦管理器
/// @param networkQuality 当前网络状态值
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager networkQualityDidChanged:(PLVBLinkMicNetworkQuality)networkQuality;

/// 本地摄像头准备就绪
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerCameraDidReady:(PLVBLinkMicManager * _Nonnull)manager;

/// 本地视频流（摄像头）关闭回调
///
/// 调用openCamera:completion:方法将触发此回调；仅在前者方法调用‘成功’后，此回调才被调用，并告知最终本地视频流的开关状态；
///
/// @param manager 连麦管理器
/// @param videoMuted 本地视频流是否关闭
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didLocalVideoMuted:(BOOL)videoMuted;

/// 本地声音监测回调
///
/// @param manager 连麦管理器
/// @param localVoiceValue 本地声音音量值；取值范围为 0.0 ~ 1.0
/// @param voiceAudible 是否接收到本地可听得见的声音（以 localVoiceValue 是否大于 0.156 为准；若需以其他值为准，可自行根据 localVoiceValue 作判断）
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager localVoiceValue:(CGFloat)localVoiceValue receivedLocalAudibleVoice:(BOOL)voiceAudible;

#pragma mark 远端用户(别人) 事件回调
/// 远端用户 加入RTC频道
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didJoinedOfUid:(NSString *)uid;

/// 远端用户 退出RTC频道
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didOfflineOfUid:(NSString *)uid;

/// 远端用户 音频流禁止状态更新回调
///
/// @param manager 连麦管理器
/// @param muted 音频流是否禁止
/// @param uid 禁止状态更新的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didAudioMuted:(BOOL)muted byUid:(NSString *)uid;

/// 远端用户 视频流禁止状态更新回调
///
/// @param manager 连麦管理器
/// @param muted 视频流是否禁止
/// @param uid 禁止状态更新的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didVideoMuted:(BOOL)muted byUid:(NSString *)uid;

#pragma mark 通用(自己、别人) 事件回调
/// 远端用户 全部流已退出房间
///
/// @note “全部流已退出房间” 不代表 “远端用户退出房间”
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager remoteUserTotalStreamsDidLeaveRoom:(NSString *)uid;

/// 全部连麦成员的音频音量 回调
///
/// @note 该回调的时间间隔约为 100ms~300ms
///
/// @param manager 连麦管理器
/// @param volumeDict 连麦成员音量字典 (key:用户连麦ID，value:对应的流的音量值；value取值范围为 0.0 ~ 1.0)
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager reportAudioVolumeOfSpeakers:(NSDictionary<NSString *, NSNumber *> * _Nonnull)volumeDict;

/// RTC频道内某位用户 ‘网络状态’ 发生改变回调
///
/// @param manager 连麦管理器
/// @param userRTCId 当前回调对应的用户RTCId
/// @param txQuality 该用户的上行网络状态
/// @param rxQuality 该用户的下行网络状态
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager userNetworkQualityDidChanged:(NSString *)userRTCId txQuality:(PLVBLinkMicNetworkQuality)txQuality rxQuality:(PLVBLinkMicNetworkQuality)rxQuality;

#pragma mark 推流事件回调
/// 推流到CDN结果
///
/// @param manager 连麦管理器
/// @param sucess 推流结果
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager streamPublishedResult:(BOOL)sucess;

/// CDN推流断流回调
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerStreamUnpublished:(PLVBLinkMicManager * _Nonnull)manager;

#pragma mark 特定场景事件回调
/// 特定场景下 获知流权限的回调事件
///
/// @return 约定的流权限
- (NSString *)plvbLinkMicManagerGetUCStreamAuthority:(PLVBLinkMicManager * _Nonnull)manager;

@end

NS_ASSUME_NONNULL_END
