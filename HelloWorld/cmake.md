# Cmake简介

当我们构建Qt应用时通常会让我们选择构建的工具是使用Cmake还是Qmake，这里简单对Cmake做一些说明。因为其实仓库的作者我是通过Qt才第一次接触Cmkae工具，所以可能还是有不少小伙伴和我一样对这个Cmake感到有点手足无措的

## 为什么选Cmake？

既然在创建应用的时候会让你选择是用Cmake还是Qmake，那么为什么不用Qt官方专门开发的Qmake工具呢？

原因其实就在于Qmake是专门给Qt用的，它不具有像Cmake那样的普适性。
如果你用`.pro`文件来配置Qt项目，这对于Qt应用来说可能确实很方便，但是你对这个文件的配置方法并不能放到其他项目里面去，但是`CMakeLists.txt`不一样，你学会了Cmake，以后你就算不写Qt了，Cmake还是很有用

## CmakeList.txt说明

使用Cmake创建项目后会自动生成一个`CMakeLists.txt`，但是这个文件里的一堆代码到底在说什么呢？

首先是通常的第一行代码：

```cmake
cmake_minimum_required(VERSION 3.5)
```

它指定了应用程序所需要的最低CMake版本

```cmake
project(helloWorld LANGUAGES CXX)
```

这是在说项目名称和使用的语言C++

```cmake
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
```

通过`set()`指令设置这些参数为`ON`表示开启自动执行`uic、moc、rcc`命令。例如会自动使用rcc命令编译.qrc文件

```cmake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

指定C++版本并保证编译器版本低于要求时打印错误

```cmake
find_package(Qt6 COMPONENTS Widgets REQUIRED)
```

寻找对应的组件

```cmake
add_executable(${PROJECT_NAME}
    WIN32
    ${srcs} 
)
```

定义可执行目标的名称、平台相关设置、想要构建成可执行文件的源文件列表

```cmake
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
```

表明生成的可执行文件需要链接到哪些模块
