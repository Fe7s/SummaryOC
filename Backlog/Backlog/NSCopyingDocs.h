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
- 没有专门定义深拷贝的协议，所以具体执行方式，由每个类自行确定。开发者只需要自己决定所写的类是否 需要提供深拷贝的方法即可。
- 遵从了NSCopying协议的对象，在大多数情况下时浅拷贝的
- 如果某个对象需要深拷贝，除非文档说明深拷贝是用NSCopying协议实现的，否则要么找到是深拷贝的方法，要么自己编写

###  关于NSZone：

在以前的时候，会根据NSZone把内存分成不同的“Zone”，对象会被创建在某个“Zone”中，现在程序只有一个“默认区”  所以现在不用管了

### 关于 - (id)copy; 和 + (id)copyWithZone:(struct _NSZone *)zone：

平时所说的对一个对象进行copy操作，则是以NSZone为“默认区”为参数，去掉用copyWithZone。

### copy immutableCopy mutableCopy
> 描述 ：为什么不设计成：copy返回的拷贝对象和目标对象保持一致、immutableCopy返回不可变对象、mutableCopy返回可变对象 ？

1、如果：copy返回的拷贝对象和目标对象保持一致
例如给NSArray *targetObject = [NSMutabArray new];此时targetObject是可变的， id copyObjet = [targetObject copy], copyObjet是不可变的，但是实际上应该是不可变的；会因为前面传入的数组类型不清楚，而引起后面使用时的错误； 所以抛弃copy只使用immutableCopy和mutableCopy

2、只使用immutableCopy 和  mutableCopy相当于copy和mutableCopy；而使用copy不使用immutableCopy的原因就是，NSCopying不只是给具有可变版本和不可变版本的类使用，有些类是没有“可变”和“不可变”的概念的

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

>- 深拷贝(内容拷贝)：拷贝对象自身时，将其底层数据也一并拷贝过来
>- 浅拷贝(指针拷贝)：只拷贝容器对象本身，不复制其中数据
>- 单层深拷贝：拷贝对象自身时，底层数据如果是多层时，只拷贝其中一层


- 不可变对象的非容器类
- 可变对象的非容器类
- 可变对象的容器类
- 不可变对象的容器类

> demo文件：demo写在- (void)systemNotVessel;和- (void)systemVessel;方法中

#### 系统非容器类:如NSString,NSMutableString

- 向不可变对象发送copy，进行的是指针拷贝；向不可变对象发送mutalbeCopy消息，进行的是内容拷贝；
- 向可变对象发送copy和mutableCopy消息，均是内容拷贝；


#### 系统容器类：如NSArray,NSDictionary

- 不可变对象copy，是指针复制；发送mutableCopy，是内容复制;
- 可变对象copy和mutableCopy均是单层内容拷贝

#### 属性修饰词

- copy：拷贝一份不可变副本赋值给属性；所以当原对象值变化时，属性值不会变化；
- strong：有可能指向一个可变对象,如果这个可变对象在外部被修改了,那么会影响该属性；

### Other

- 让自己写的类具有拷贝功能，需要实现NSCopying协议
- 让自己写的类具有可变版本，遵守NSMutableCopying协议；自己写的类具有不可变版本，遵守NSCopying协议；
- 复制对象时需要考虑是深拷贝还是浅拷贝，一般是浅拷贝，如果所写的对象需要深拷贝，那么最好写一个专门执行深考本的方法


#endif /* NSCopyingDocs_h */
