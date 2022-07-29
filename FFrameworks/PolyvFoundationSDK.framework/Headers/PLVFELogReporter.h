//
//  PLVFELogReporter.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/5.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <PolyvFoundationSDK/PolyvFoundationSDK.h>
#import "PLVFLogReporter.h"

@class PLVFELogModel;

NS_ASSUME_NONNULL_BEGIN

/*
 Elog日志上报器，唯一需要获取用户账号信息的日志上报器，支持批量日志上报
 */
@interface PLVFELogReporter : PLVFLogReporter

/// productType 为 PLVProductTypeVod 的登陆接口
- (void)registerWithUserId:(NSString *)userId secretkey:(NSString *)secretkey;

/// productType 为 PLVProductTypeLive 或 PLVProductTypeStreamer 的登陆接口
- (void)registerWithChannelId:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret userId:(NSString *)userId;

/// productType 为 PLVProductTypeLive 回放场景下的登陆接口
- (void)registerWithChannelId:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret userId:(NSString *)userId vId:(NSString *)vid;

/// 登出接口
- (void)unregister;

/// 生成模版数据模型，模型中已包含通用的基础信息
- (PLVFELogModel *)generateTemplateModel;

@end

NS_ASSUME_NONNULL_END
