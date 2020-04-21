//
//  FESDesigatedInitalizerDemo.h
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/21.
//  Copyright © 2020 Fe7s. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FESDesigatedInitalizerDemo : NSObject<NSCoding>

//-(instancetype)init NS_UNAVAILABLE;

/// 初始化放羊娃爹爹管理的羊群和牧羊犬的数量,指定初始化方法
/// @param sheep 羊群数
/// @param shepherdDog 牧羊犬数
- (instancetype)initWithSheep:(NSInteger)sheep andShepherdDog:(NSInteger)shepherdDog NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
