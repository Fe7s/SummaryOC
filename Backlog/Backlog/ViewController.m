//
//  ViewController.m
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/14.
//  Copyright © 2020 Fe7s. All rights reserved.
//

#import "ViewController.h"
#import "FESCopyDemo.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    // 自定义类的copy使用
//    [self customCopyingDemo];
//    [self systemNotVessel];
    [self systemVessel];
    
    
    
    
    
}

#pragma mark - Copy

/// 自定义类的copy使用 （NSMutableCopying和NSCopying相似）
- (void)customCopyingDemo {
    // 使用自定义初始化方法初始化FESCopyDemo，其中_demoName参数传值为@"demo"
    FESCopyDemo *demo = [[FESCopyDemo alloc]initWithDemoName:@"demo"];
    [demo addCopyDemo:@"usedName0"];

    // copy会以NSZone为“默认区”为参数，去掉用copyWithZone:，也就是FESCopyDemo遵守NSCopying协议重写的copyWithZone方法
    FESCopyDemo *copyDemo = [demo copy];
    
    // 打印demo和copyDemo的地址
    NSLog(@"\ndemo:%p \ncopyDemo:%p", demo, copyDemo);
    NSLog(@"\ndemo:%@ \ncopyDemo:%@", demo, copyDemo);
    
    [demo addCopyDemo:@"usedName1"];
    [copyDemo addCopyDemo:@"usedName2"];
    NSLog(@"\ndemo:%@ \ncopyDemo:%@", demo, copyDemo);
}

/// 系统非容器类:如NSString,NSMutableString
- (void)systemNotVessel {
    // 1、对 非容器类，不可变对象进行copy和MutableCopy
    NSString *str1 = @"非容器类，不可变对象";
    // 指针拷贝
    NSString *str2 = [str1 copy];
    // 内容拷贝
    NSMutableString *str3 = [str1 mutableCopy];
    NSLog(@"str1 is %p, str2 is %p, str3 is %p",str1, str2, str3);
    // 向不可变对象发送copy，进行的是指针拷贝；向不可变对象发送mutalbeCopy消息，进行的是内容拷贝；

    
    // 2、对非容器类，可变对象进行copy和MutableCopy
    NSMutableString *str11 = [NSMutableString stringWithFormat:@"非容器类，可变对象"];
    // 内容拷贝
    NSString *str12 = [str11 copy];
    // 内容拷贝
    NSMutableString *str13 = [str11 mutableCopy];
    NSLog(@"str11 is %p, str12 is %p, str13 is %p",str11, str12, str13);
    // 向可变对象发送copy和mutableCopy消息，均是内容拷贝；


    // 3、拷贝之后的实际类型
    NSString *str21 = @"123";
    NSString *str22 = [str21 copy];
    NSMutableString *str23 = [str21 copy];
    NSMutableString *str24 = [str21 mutableCopy];
    // [str copy] copy出来的是不可变对象，即使mustr是用NSMutableString修饰，使用appendString依然会崩溃
    // reason: 'Attempt to mutate immutable object with appendString:
    // [str23 appendString:@"4"];
    [str24 appendString:@"5"];
    NSLog(@"str21 is %@, str22 is %@, str23 is %@ str24 is %@",str21, str22, str23, str23);
    
    // [immutbale copy] => immutable
    // [immutable mutableCopy] => mutable

    
}



/// 系统容器类：如NSArray,NSDictionary
- (void)systemVessel {
    // 1、对容器类，不可变对象进行copy和MutableCopy
    NSArray *array1 = [NSArray arrayWithObjects:@"1", nil];
    // 指针拷贝
    NSArray *copyArray1 = [array1 copy];
    // 内容拷贝
    NSMutableArray *mutableCopyArray1 = [array1 mutableCopy];
    NSLog(@"array1 is %p,  copyArray1 is %p,  mutableCopyArray1 is %p",
          array1, copyArray1, mutableCopyArray1);
    // 不可变对象copy，是指针拷贝；mutableCopy，是内容复制;

    
    // 2、对非容器类，可变对象进行copy和MutableCopy
    NSMutableArray *element = [NSMutableArray arrayWithObject:@1];
    NSMutableArray *array2 = [NSMutableArray arrayWithObject:element];
    // 单层内容拷贝
    NSArray *copyArray2 = [array2 copy];
    // 单层内容拷贝
    NSMutableArray *mutableCopyArray2 = [array2 mutableCopy];

    NSLog(@"array2 is %p,  copyArray2 is %p,  mutableCopyArray2 is %p", array2, copyArray2, mutableCopyArray2);
    
    // 单层内容拷贝
    NSMutableArray *elem = [NSMutableArray arrayWithObject:@2];
    [mutableCopyArray2 addObject:elem];
    NSLog(@"element is %@,  array is %@,  copyArray is %@,  mutableCopyArray is %@", element,array2,copyArray2, mutableCopyArray2);

    // 单层往下不拷贝,会同时修改
    [mutableCopyArray2[0] addObject:@2];
    NSLog(@"element is %@,  array is %@,  copyArray is %@,  mutableCopyArray is %@", element, array2, copyArray2, mutableCopyArray2);
    // 可变对象copy和mutableCopy均是单层内容拷贝；

    // 3、拷贝之后的实际类型
    NSMutableArray *mutableArray = [NSMutableArray arrayWithObjects:@"1",@"2",@"3", nil];
    NSArray *arrayCopy = [mutableArray copy];
    NSArray *arrayMutableCopy = [mutableArray mutableCopy];
    NSMutableArray *mutableArrayCopy = [mutableArray copy];
    NSMutableArray *mutableArrayMutableCopy = [mutableArray mutableCopy];
    
    // 注意实际类型
    // reason: '-[__NSArrayI addObject:]: unrecognized selector sent to instance 0x6000031b4ed0'
    //[mutableArrayCopy addObject:@"4"];
    NSLog(@"mutableArray:%@   arrayCopy:%@   arrayMutableCopy:%@   mutableArrayCopy:%@   mutableArrayMutableCopy:%@",
          mutableArray, arrayCopy, arrayMutableCopy, mutableArrayCopy, mutableArrayMutableCopy);
    // [mutbale copy] => immutable
    // [mutable mutableCopy] => mutable
}



@end
