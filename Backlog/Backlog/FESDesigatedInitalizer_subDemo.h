//
//  FESDesigatedInitalizer_subDemo.h
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/21.
//  Copyright © 2020 Fe7s. All rights reserved.
//

#import "FESDesigatedInitalizerDemo.h"

NS_ASSUME_NONNULL_BEGIN

@interface FESDesigatedInitalizer_subDemo : FESDesigatedInitalizerDemo<NSCoding>


/// 初始化放羊娃
/// @param shepherdDog 放羊娃带领的牧羊犬个数
-(instancetype)initWithShepherdDog:(NSInteger)shepherdDog NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
