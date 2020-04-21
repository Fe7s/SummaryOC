//
//  FESDesigatedInitalizer_subDemo.m
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/21.
//  Copyright © 2020 Fe7s. All rights reserved.
//
// 这里写一个功能：放羊娃，年纪尚小只能带着牧羊犬并不能照顾羊群

#import "FESDesigatedInitalizer_subDemo.h"

@implementation FESDesigatedInitalizer_subDemo

 
/**
 *如果子类的指定初始化方法和超类的指定初始化方法名称不同，那么应该覆写超类的指定初始化方法
 *Method override for the designated initializer of the superclass '-initWithSheep:andShepherdDog:' not found
 */
- (instancetype)initWithSheep:(NSInteger)sheep andShepherdDog:(NSInteger)shepherdDog {
    // 调用放羊娃的指定初始化方法
    return [self initWithShepherdDog:shepherdDog];
}

- (instancetype)initWithShepherdDog:(NSInteger)shepherdDog {
    // 调用超类类的指定初始化方法
    return [super initWithSheep:0 andShepherdDog:shepherdDog];
}

- (instancetype)initWithCoder:(NSCoder *)decoder {
    if (self = [super initWithCoder:decoder]) {
        
    }
    return self;
}

@end
