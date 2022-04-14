//
//  PLVSpeakMessage.h
//  PLVLiveScenesSDK
//
//  Created by MissYasiky on 2020/11/24.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVSpeakMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, copy) NSString *content;

@property (nonatomic, assign)NSTimeInterval time;

@end

NS_ASSUME_NONNULL_END
