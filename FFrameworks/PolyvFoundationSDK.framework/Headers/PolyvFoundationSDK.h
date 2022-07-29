//
//  PolyvFoundationSDK.h
//  PolyvFoundationSDK
//
//  Created by zykhbl on 2018/8/2.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for PolyvFoundationSDK.
FOUNDATION_EXPORT double PolyvFoundationSDKVersionNumber;

//! Project version string for PolyvFoundationSDK.
FOUNDATION_EXPORT const unsigned char PolyvFoundationSDKVersionString[];

#import <PolyvFoundationSDK/PLVConfig.h>

/*----------- 工具类 ------------*/

#import <PolyvFoundationSDK/PLVFdUtil.h>
#import <PolyvFoundationSDK/PLVDataUtil.h>
#import <PolyvFoundationSDK/PLVColorUtil.h>
#import <PolyvFoundationSDK/PLVNetworkError.h>
#import <PolyvFoundationSDK/PLVFNetworkUtil.h>
#import <PolyvFoundationSDK/PLVFFileUtil.h>
#import <PolyvFoundationSDK/PLVFWeakProxy.h>
#import <PolyvFoundationSDK/PLVViewFrameUtil.h>
#import <PolyvFoundationSDK/PLVNetworkAccessibility.h>

/*----------- 日志类 ------------*/

#import <PolyvFoundationSDK/PLVFUserAgentBuilder.h>
#import <PolyvFoundationSDK/PLVFBaseLogReporter.h>
#import <PolyvFoundationSDK/PLVFLogReporter.h>
#import <PolyvFoundationSDK/PLVFELogReporter.h>
#import <PolyvFoundationSDK/PLVFViewLogReporter.h>
#import <PolyvFoundationSDK/PLVFQosLogReporter.h>
#import <PolyvFoundationSDK/PLVFLogModel.h>
#import <PolyvFoundationSDK/PLVFViewLogModel.h>
#import <PolyvFoundationSDK/PLVFQosLogModel.h>
#import <PolyvFoundationSDK/PLVFELogModel.h>

/*----------- 错误码 ------------*/

#import <PolyvFoundationSDK/PLVFErrorBaseCodeDefine.h>
#import <PolyvFoundationSDK/PLVFPlayErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFDownloadErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFUploadErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFRecordErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFRtmpErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFChatErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFLinkErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFPPTErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFInitErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFSocketErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFHttpErrorCodeGenerator.h>
#import <PolyvFoundationSDK/PLVFInteractionErrorCodeGenerator.h>

/*----------- 内部库 ------------*/

// 安全模型
#import <PolyvFoundationSDK/PLVSafeModel.h>

// 控制台日志
#import <PolyvFoundationSDK/PLVFConsoleLogger.h>

// JSBridge
#import <PolyvFoundationSDK/PLVJSBridge.h>

// 授权校验
#import <PolyvFoundationSDK/PLVAuthorizationManager.h>

// 视频跑马灯
#import <PolyvFoundationSDK/PLVMarqueeModel.h>
#import <PolyvFoundationSDK/PLVVideoMarquee.h>

/*----------- 重命名开源库 ------------*/

// 浮窗显示
#import <PolyvFoundationSDK/PLVProgressHUD.h>

// 网络检测
#import <PolyvFoundationSDK/PLVReachability.h>

// WebViewJavascriptBridge
#import <PolyvFoundationSDK/PLVFWebViewJavascriptBridge_JS.h>
#import <PolyvFoundationSDK/PLVFWebViewJavascriptBridgeBase.h>
#import <PolyvFoundationSDK/PLVFWKWebViewJavascriptBridge.h>

// 多播代理
#import <PolyvFoundationSDK/PLVMulticastDelegate.h>

