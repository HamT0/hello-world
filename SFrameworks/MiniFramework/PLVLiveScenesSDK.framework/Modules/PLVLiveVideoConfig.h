//
//  PLVLiveVideoConfig.h
//  PLVLiveScenesSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PLVFoundationSDK/PLVConfig.h>

/**
 直播 SDK 配置文件
 */
@interface PLVLiveVideoConfig : NSObject<PLVConfig>

/// 是否已配置有效userId、appId、appSecret，默认为NO，有效指非空字符串
@property (nonatomic, assign, readonly) BOOL configAccount;
/// 可配置chatApi私有域名
@property (nonatomic, strong, readonly) NSString *chatApiDomain;
/// 推流参数
@property (nonatomic, copy, readonly) NSDictionary *clientParams;

/// 弹出相册或相机时不能横竖屏切换
@property (nonatomic, assign) BOOL unableRotate;
/// 互动页面此时是否不能横竖屏切换
@property (nonatomic, assign) BOOL triviaCardUnableRotate;
/// 是否启用 HttpDNS，默认开启
@property (nonatomic, assign) BOOL enableHttpDNS;
/// 是否启用 IPV6，如果启用，将自动选择IP，取消HttpDNS
@property (nonatomic, assign) BOOL enableIPV6;

+ (instancetype)sharedInstance;

/// 配置账号信息
/// PLV 后台，云直播->开发设置->身份认证：userId、AppID、AppSecret参数
/// @param userId 用户ID
/// @param appId 应用ID
/// @param appSecret 应用密钥
- (BOOL)configWithUserId:(NSString *)userId appId:(NSString *)appId appSecret:(NSString *)appSecret;

/**
 私有域名配置
 */
+ (void)setPrivateDomainWithData:(NSDictionary *)data;


@end
