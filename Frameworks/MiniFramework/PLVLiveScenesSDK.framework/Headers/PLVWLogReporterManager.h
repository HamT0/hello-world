//
//  PLVWLogReporterManager.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2019/12/23.
//  Copyright © 2019 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVFoundationSDK/PLVFoundationSDK.h>

@class PLVFViewLogModel, PLVFELogReporter, PLVChannelInfoModel, PLVViewLogCustomParam;

NS_ASSUME_NONNULL_BEGIN

@interface PLVWLogReporterManager : NSObject

+ (instancetype)sharedManager;

#pragma mark - ELog

/**
 Elog 上报器初始化接口 1
 云课堂直播间登录时调用
 */
- (void)registerReporterWithChannelId:(NSString *)channelId
                                appId:(NSString *)appId
                            appSecret:(NSString *)appSecret
                               userId:(NSString *)userId;

/**
 Elog 上报器初始化接口 2
 云课堂回放登录时调用
 */
- (void)registerReporterWithChannelId:(NSString *)channelId
                                appId:(NSString *)appId
                            appSecret:(NSString *)appSecret
                               userId:(NSString *)userId
                                  vId:(NSString *)vId;

/**
 Elog 上报器初始化接口 3
 手机开播、互动学堂登录时调用
 @note 仅在productType为PLVProductTypeStreamer或PLVProductTypeHiClass时生效
 */
- (void)registerReporterWithChannelId:(NSString *)channelId productType:(PLVFLogProductType)productType;

/**
 Elog 上报器登录信息清除接口
 云课堂直播/回放退出登录时调用
 */
- (void)clear;

/**
Elog 上报器错误日志上报接口 1
*/
- (void)reportWithErrorCode:(NSInteger)errorCode
                information:(id __nullable)information;

/**
 Elog 事件上报便利接口 1
 */
- (void)reportWithEvent:(NSString *)event
                  modul:(NSString *)modul
        informationType:(NSString * __nullable)type
        informationData:(id __nullable)data;

/**
Elog 事件上报便利接口 2
*/
- (void)reportWithEvent:(NSString *)event
                  modul:(NSString *)modul
            information:(id __nullable)information;

/**
Elog 事件上报便利接口 1 - 批量上报
*/
- (void)reportWithEvent:(NSString *)event
                  modul:(NSString *)modul
        informationType:(NSString * __nullable)type
        informationData:(id __nullable)data
                  patch:(BOOL)patch;

/**
Elog 事件上报便利接口 2 - 批量上报
*/
- (void)reportWithEvent:(NSString *)event
                  modul:(NSString *)modul
            information:(id __nullable)information
                  patch:(BOOL)patch;

#pragma mark - View Log

/**
直播播放信息统计：用于直播、回放时
@param param 统计后台用户自定义参数配置类
@param playerId 播放器ID
*/
- (void)reportLiveViewLogWithParam:(PLVViewLogCustomParam *)param
                          playerId:(NSString *)playerId
               logModelConfigBlock:(PLVFViewLogModel *(^)(void))configBlock;

/**
点播播放信息统计：用于播放点播视频时
 @param param 统计后台用户自定义参数配置类
 @param playerId 播放器ID
*/
- (void)reportVodViewLogWithParam:(PLVViewLogCustomParam *)param
                         playerId:(NSString *)playerId
              logModelConfigBlock:(PLVFViewLogModel *(^)(void))configBlock;

#pragma mark - Qos

/**
服务质量统计
*/
/**
直播首次加载时长
@param channel 频道信息
@param time 首次加载时长
@param playerId 播放器ID
*/
- (void)reportLiveLoadingQosWithChannel:(PLVChannelInfoModel *)channel
                                   time:(int)time
                               playerId:(NSString *)playerId;

/**
回放首次加载时长
@param channel 频道信息
@param time 首次加载时长
@param playerId 播放器ID
@param vid 视频vid
*/
- (void)reportVodLoadingQosWithChannel:(PLVChannelInfoModel *)channel
                                  time:(int)time
                              playerId:(NSString *)playerId
                                   vid:(NSString *)vid;

/**
 直播二次缓冲时长
 @param channel 频道信息
 @param time 二次缓冲时长
 @param playerId 播放器ID
 */
- (void)reportLiveBufferQosWithChannel:(PLVChannelInfoModel *)channel
                                  time:(int)time
                              playerId:(NSString *)playerId;

/**
 回放二次缓冲时长
 @param channel 频道信息
 @param time 二次缓冲时长
 @param playerId 播放器ID
 @param vid 视频vid
 */
- (void)reportVodBufferQosWithChannel:(PLVChannelInfoModel *)channel
                                 time:(int)time
                             playerId:(NSString *)playerId
                                  vid:(NSString *)vid;

/**
 直播播放出错
@param channel 频道信息
@param uri 请求资源的URI
@param status 服务器响应的状态码
@param errorcode 错误代码
@param errormsg 错误内容描述
@param playerId 播放器ID
*/
- (void)reportLiveErrorQosWithChannel:(PLVChannelInfoModel *)channel
                                  uri:(NSString *)uri
                               status:(NSString *)status
                            errorcode:(NSString *)errorcode
                             errormsg:(NSString *)errormsg
                             playerId:(NSString *)playerId;

/**
 回放播放出错
@param channel 频道信息
@param uri 请求资源的URI
@param status 服务器响应的状态码
@param errorcode 错误代码
@param errormsg 错误内容描述
@param playerId 播放器ID
@param vid 视频vid
*/
- (void)reportVodErrorQosWithChannel:(PLVChannelInfoModel *)channel
                                 uri:(NSString *)uri
                              status:(NSString *)status
                           errorcode:(NSString *)errorcode
                            errormsg:(NSString *)errormsg
                            playerId:(NSString *)playerId
                                 vid:(NSString *)vid;

@end

NS_ASSUME_NONNULL_END
