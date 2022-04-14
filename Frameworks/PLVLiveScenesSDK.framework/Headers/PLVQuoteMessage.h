//
//  PLVQuoteMessage.h
//  PLVLiveScenesDemo
//
//  Created by MissYasiky on 2020/11/25.
//  Copyright © 2020 PLV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVQuoteMessage : NSObject

@property (nonatomic, copy) NSString * _Nullable msgId;

@property (nonatomic, copy) NSString *content;

@property (nonatomic, copy) NSString *quoteMsgId;

@property (nonatomic, copy) NSString *quoteUserId;

@property (nonatomic, copy) NSString *quoteUserName;

@property (nonatomic, copy) NSString * _Nullable quoteContent;

@property (nonatomic, copy) NSString * _Nullable quoteImageUrl;

@property (nonatomic, assign) CGSize quoteImageSize;

@property (nonatomic, assign)NSTimeInterval time;

@end

NS_ASSUME_NONNULL_END
