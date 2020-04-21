//
//  FESDesigatedInitalizerDemo.m
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/21.
//  Copyright © 2020 Fe7s. All rights reserved.
//
// 这里写一个功能：有一个放羊娃的爹爹，羊群和牧羊犬

#import "FESDesigatedInitalizerDemo.h"

@interface FESDesigatedInitalizerDemo ()

@property (nonatomic, assign, readonly) NSInteger sheep;//!< 羊群数量（不可修改）
@property (nonatomic, assign, readonly) NSInteger shepherdDog;//!< 牧羊犬数量 （不可修改）

@end

@implementation FESDesigatedInitalizerDemo

/// 复写超类的指定初始化方法
- (instancetype)init {
    if (self = [self initWithSheep:10 andShepherdDog:10]) {
        
    }
    
    // 调用指定初始化方法,默认设置羊群和牧羊犬数量
    return [self initWithSheep:10 andShepherdDog:10];
}

///**
// * 建议必须使用指定初始化方法，不希望使用者使用init方法初始化，可以抛出异常
// * 但一般情况下只有发生严重错误才使用抛出异常
// */
//- (instancetype)init {
//    @throw [NSException exceptionWithName:NSInternalInconsistencyException reason:@"请使用initWithSheep: andShepherdDog:代替" userInfo:nil];
//}

- (instancetype)initWithSheep:(NSInteger)sheep andShepherdDog:(NSInteger)shepherdDog {
    // 调用超类的指定初始化方法init;
    self = [super init];
    if (self) {
        _sheep = sheep;
        _shepherdDog = shepherdDog;
    }
    return self;
}

/**
 * 假设一种场景，有N(N>2)个初始化方法
 * 方法一：只分配一个指定初始化方法，另外N-1个方法，在初始化对象时都使用指定初始化方法
 * 方法二：没有指定初始化方法，每个初始化方法，都对创建对象设置属性sheep和shepherdDog有自己的编写方法，那么核心的对设置属性sheep和shepherdDog赋值修改时，要每个初始化方法都要重新修改一遍，如果N很大或者多人维护代码时，极有可能会出现问题
 */

- (void)encodeWithCoder:(nonnull NSCoder *)coder {
    
}

- (nullable instancetype)initWithCoder:(nonnull NSCoder *)decoder {
    if (self = [super init]) {
        _sheep       = [decoder decodeIntForKey:@"sheep"];
        _shepherdDog = [decoder decodeIntForKey:@"shepherdDog"];
    }
    return self;
}

@end
