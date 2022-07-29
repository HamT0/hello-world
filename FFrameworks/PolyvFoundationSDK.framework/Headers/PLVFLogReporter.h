//
//  PLVFLogReporter.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/11/29.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLVFBaseLogReporter.h"

NS_ASSUME_NONNULL_BEGIN

/*
 PLVFBaseLogReporter的子类，负责日志的批量上报、失败重试的逻辑，不包含业务逻辑
 */
@interface PLVFLogReporter : PLVFBaseLogReporter

/// 日志上报接口
/// @param model 用PLVFLogModel模型封装的日志上报的信息（PLVFLogModel需要根据日志类型进行子类化）
- (void)reportModel:(PLVFLogModel *)model;

@end

NS_ASSUME_NONNULL_END
