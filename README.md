# Qt-Beginner

![Qt](https://img.shields.io/badge/Qt-6\.8\.1-darkgreen)
![Language](https://img.shields.io/badge/Language-Cpp-blue)
![license](https://img.shields.io/badge/License-MIT-red)

Record the code I left behind while learning Qt6 programming. The repository contains some very basic application examples written using Qt6.

记录自己初学Qt6编程的点点滴滴，仓库中包含一些非常简单的Qt6示例程序，希望自己能坚持学习！

> [!Important]
> 仓库中的示例均是在`VScode + MinGW + CMake`环境下生成的，因此其中的文件目录结构与`QCreator + QMake`环境下的开发存在一定区别，可能需要经过调整后才能查看运行效果

---

## 内容介绍

- `HelloWorld` - **你好！Qt**  
  这是一个空的应用程序示例，由`VSC + MinGW + CMake`环境配置下生成的模板，也是每一次开发所必须的第一个步骤
- `QtWidgets` - **基本组件**  
  该应用程序含有QWidgets中一些基本组件的使用例子，比如按钮、文本框、标签等，并且只包含组件的基本显示，并不包含信号和槽机制以及布局管理
- `QtLayouts` - **布局管理**  
  展示了Qt Widgets中基本的布局管理方式，包含多个按钮在水平布局、垂直布局、网格布局下的展示情况
- `Signal-Slot` - **信号和槽**  
  简单演示信号和槽的工作机制，应用包含一个按钮、一个标签和一个文本框，按下按钮能够改变标签的显示文本，修改文本框内容也能让标签同步显示更改后的文本内容
- `mainWindow` - **主窗口**  
  一个简单的应用程序主窗口示例，展示QMainWindow类的基本使用，包含菜单栏、工具栏、中心部件、Dock部件与状态栏的应用示例
- `EventsSystem` - **事件系统**  
  Qt6中事件系统的简单示例，展示对鼠标、键盘、计时器与拖拽等事件的基本应用
- `QSS` - **外观样式**  
  简单展示Qt中如何像CSS那样控制各个组件的样式，代码完成了基本的主题切换功能
- `I18Ndoc` - **国际化**  
  有关于对Qt应用国际化的简单文档
- `AnimationFramework` - **动画框架**  
  以一个Q弹的按钮演示Qt中动画模块的应用
- `ModelView` - **模型视图**  
  以自定义模型类、委托类的形式简单展示Qt中模型、视图、委托的用法
- `SqlWithQt` - **数据库**  
  简单演示Qt如何连接数据库并做基本的增删改查等操作
