//
//  Outline.h
//  NoClassifiedSunmmary
//
//  Created by Dove on 2020/4/10.
//  Copyright © 2020 Fe7s. All rights reserved.
//
// 概述

#ifndef Outline_h
#define Outline_h

#### JSON解析
---
- 轻量级数据格式，一般用于数据交互
- 形式上类似于字典和数组
- 解析方案：
    
    > 1、第三方框架
    JSONKit
    SBJSON
    TouchJson
        
    >2、原生
    NSJONSerialization
    
转换
1、json->OC对象
2、OC对象->json对象
3、OC对象和JSON数据格式之间的一一对应关系

查看JSON数据
1、在线
2、转成plist文件

相关框架：

- mantle ： 需要继承自MTModle
- JSONModel： 需要继承自JSONModel
- MJExtension：不需要继承，无代码入侵

自己设计需要注意点

- 侵入性
- 易用性
- 扩展性

---


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



#endif /* Outline_h */
