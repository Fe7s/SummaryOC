//
//  NSCopyingDocs.h
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/17.
//  Copyright © 2020 Fe7s. All rights reserved.
//
// ## 关于协议：NSCopying  和NSMutableCopying

#ifndef NSCopyingDocs_h
#define NSCopyingDocs_h

## 关于协议：NSCopying  和NSMutableCopying

---
### 协议：
- @protocol NSCopying
> -(id)copyWithZone:(nullable NSZone *)zone;
     
- @protocol NSMutableCopying
>  -(id)mutableCopyWithZone:(nullable NSZone *)zone;
  
---
### 如果想让自己实现的类支持copy操作：

- 遵守以上协议
- 实现协议方法

> demo文件：自定义的demo写在FESCopyDemo.h里，使用写在- (void)customCopyingDemo;方法中

类的对象的copy：

- 类直接继承自NSObject，无需调用[super copyWithZone:zone]
- 父类实现了copy协议，子类也实现了copy协议，子类需要调用[super copyWithZone:zone]
- 父类没有实现copy协议，子类实现了copy协议，子类无需调用[super copyWithZone:zone]
- copyWithZone方法中要调用[[[self class] alloc] init]来分配内存

### 自定义的类实现深拷贝
（待补充）

###  关于NSZone：

在以前的时候，会根据NSZone把内存分成不同的“Zone”，对象会被创建在某个“Zone”中，现在程序只有一个“默认区”  所以现在不用管了

### 关于 - (id)copy; 和 + (id)copyWithZone:(struct _NSZone *)zone：

平时所说的对一个对象进行copy操作，则是以NSZone为“默认区”为参数，去掉用copyWithZone。

### copy immutableCopy mutableCopy
(待补充)


###  关于 - (void)copy; 和 - (void)mutableCopy;
>**无论当前对象是否可变：**
>
>发送copy消息，拷贝出来的是不可变对象;

>发送mutableCopy消息，拷贝出来的是可变对象;

```
[immutbale copy] => immutable
[immutable mutableCopy] => mutable

[mutbale copy] => immutable
[mutable mutableCopy] => mutable
```


### 深拷贝(内容拷贝) 、 浅拷贝    (指针拷贝)、 单层深拷贝(多层数据只拷贝一层)

（解释待补充）


- 不可变对象的非容器类
- 可变对象的非容器类
- 可变对象的容器类
- 不可变对象的容器类

系统非容器类:如NSString,NSMutableString

- 向不可变对象发送copy，进行的是指针拷贝；向不可变对象发送mutalbeCopy消息，进行的是内容拷贝；
- 向可变对象发送copy和mutableCopy消息，均是内容拷贝；


系统容器类：如NSArray,NSDictionary

- 不可变对象copy，是指针复制；发送mutableCopy，是内容复制;
- 可变对象copy和mutableCopy均是单层内容拷贝


属性修饰词

- copy：拷贝一份不可变副本赋值给属性；所以当原对象值变化时，属性值不会变化；
- strong：有可能指向一个可变对象,如果这个可变对象在外部被修改了,那么会影响该属性；






#endif /* NSCopyingDocs_h */
