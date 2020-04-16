//
//  FESCopyDemo.m
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/14.
//  Copyright © 2020 Fe7s. All rights reserved.
//

#import "FESCopyDemo.h"

// 遵守NSCopying协议
@interface FESCopyDemo ()<NSCopying>

@property (nonatomic, copy) NSString *demoName;

@end

@implementation FESCopyDemo
{
    // 前提设置: 设置这个数组，用来增删曾用名，并且在初始化方法中不从外部传入
    NSMutableArray<NSString *> *_usedNameArray; //!< 曾用名数组，用来存储NSString类型对象
}

- (instancetype)init{
    if (self = [super init]) {
        
    }
    return self;
}

- (instancetype)initWithDemoName:(NSString *)demoName{
    if (self = [super init]) {
        _demoName = demoName;
        // 初始化_copyDemoArray
        _usedNameArray = [[NSMutableArray alloc]init];
    }
    return self;
}

/// 重写NSCopying协议的方法
/// @param zone “默认区”
- (id)copyWithZone:(NSZone *)zone {
    FESCopyDemo *copyDemo = [[[self class] allocWithZone:zone]initWithDemoName:_demoName];
    
    // copy 创建出来之后，copyDemo->_usedNameArray是空的， 所以要把_usedNameArray给copyDemo->_usedNameArray
    // 如果是可变的那么要使用[_usedNameArray mutableCopy]
    // 根据深浅拷贝来判定
    copyDemo->_usedNameArray = [_usedNameArray mutableCopy]; // _usedNameArray;

    // 打印copy出来的新的对象
    NSLog(@"\nself:%p  \ncopyDemo:%p",self, copyDemo);
    return copyDemo;
}

#pragma mark - Action

- (void)addCopyDemo:(NSString *)usedName {
    [_usedNameArray addObject:usedName];
    [self description];
}

- (void)removeCopyDemo:(NSString *)usedName {
    [_usedNameArray removeObject:usedName];
}

/// 重写，自定义输出内容
- (NSString *)description {
    return [NSString stringWithFormat:@"<%@ : %p demoName:%@ usedName:%@>",[self class], self, _demoName, _usedNameArray];
}
@end
