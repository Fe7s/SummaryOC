//
//  FESCopyDemo.h
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/14.
//  Copyright © 2020 Fe7s. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FESCopyDemo : NSObject

/// 初始化方法
/// @param demoName demoName
- (instancetype)initWithDemoName:(NSString *)demoName;

/// 给_copyDemoArray数组添加的NSString对象
/// @param usedName 曾用名
- (void)addCopyDemo:(NSString *)usedName;

/// 从_copyDemoArray数组中删除NSString对象
/// @param usedName 曾用名
- (void)removeCopyDemo:(NSString *)usedName;



@end

NS_ASSUME_NONNULL_END
