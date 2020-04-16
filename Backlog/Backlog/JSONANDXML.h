//
//  JSONANDXML.h
//  Backlog
//
//  Created by 鹤九霄 on 2020/4/14.
//  Copyright © 2020 Fe7s. All rights reserved.
//
// JSON解析 和 XML解析

#ifndef JSONANDXML_h
#define JSONANDXML_h



#### JSON解析
---
##### 简单的特点：

- 轻量级数据格式，一般用于数据交互
- 形式上类似于字典和数组
- 只需读取JSON字符串
    
#####  解析方案：

1、第三方框架：

- JSONKit

    > 6.2K
    > 旧 2012年的产物
    >  停更
    > C
    > MRC
    > 适用于iOS5.0以下版本
    > 号称效率高

- SBJSON
    > 仍在维护
    >  效率只比touchJSON好一点
    > 可以读读源码学习一波
- TouchJson
    > 不足1K
    > 停更
    > 效率低
- YAJL
    > C
    > 停更 5years age
    
2、原生

- NSJONSerialization
    
##### 转换:    binary <--> Foundation object
1、json->OC对象
2、OC对象->json对象
3、OC对象和JSON数据格式之间的一一对应关系

##### 查看JSON数据的方式
1、在线
2、专程plist文件

##### 数据转模型相关框架：

- mantle ： 需要继承自MTModle
- JSONModel： 需要继承自JSONModel
- MJExtension：不需要继承，无代码入侵

##### 自己设计需要注意点

- 侵入性
- 易用性
- 扩展性mac






#### XML解析
---
- 可扩展语言

解析方式：
1、SAX：从根元素开始，按顺序一个一个元素往下解析
2、DOM：一次性将整个XML文档加载到内存中，适合较小的文件

 解析工具：

> 1、原生
> NSXMLParaser：使用SAX方式解析，使用简单
>
> 2、第三方框架
>  libxml2:纯C语言，默认包含在iOS SDK中，同时支持DOM和SAX的方式解析
>  GDataXML：采用DOM方式解析，由Google开发，是基于xml2的
    

多值参数和中文输出的问题
多值参数如何设置请求路径
如何解决字典和数组中输出乱码的问题

[url](https://www.jianshu.com/p/e777e13b6246)



#endif /* JSONANDXML_h */
