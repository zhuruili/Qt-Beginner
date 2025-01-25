#include "mainwindow.h"

#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QStatusBar>
#include <QTextEdit>
#include <QAction>
#include <QIcon>
#include <QLabel>
#include <QProgressBar>

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口标题
    setWindowTitle("主窗口");

    // 创建菜单栏
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // 创建文件菜单
    QMenu *fileMenu = menuBar->addMenu("文件");
    QAction *newAction = fileMenu->addAction("新建");
    QAction *openAction = fileMenu->addAction("打开");
    QAction *saveAction = fileMenu->addAction("保存");
    fileMenu->addSeparator(); // 添加分隔符
    QAction *exitAction = fileMenu->addAction("退出");

    // 创建编辑菜单
    QMenu *editMenu = menuBar->addMenu("编辑");
    QAction *cutAction = editMenu->addAction("剪切");
    QAction *copyAction = editMenu->addAction("复制");
    QAction *pasteAction = editMenu->addAction("粘贴");

    // 创建工具栏
    QToolBar *toolBar = addToolBar("工具栏");
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addSeparator();
    toolBar->addAction(cutAction);
    toolBar->addAction(copyAction);
    toolBar->addAction(pasteAction);

    // 创建中心部件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // 创建 Dock 部件
    QDockWidget *dockWidget = new QDockWidget("Dock 部件", this);
    QTextEdit *dockTextEdit = new QTextEdit(dockWidget);
    dockWidget->setWidget(dockTextEdit);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget); // 将 Dock 部件添加到主窗口的左侧

    // 创建状态栏
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    // statusBar->showMessage("就绪"); // 临时消息
    // statusBar->showMessage("当第二个参数为 0 时，消息会一直显示", 0);  // 永久消息

    // 添加进度条（可被覆盖）
    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setMaximum(100);
    progressBar->setValue(50);
    progressBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed); // 设置大小策略
    statusBar->addWidget(progressBar);

    // 添加永久消息
    QLabel *permanentLabel = new QLabel("通知", this);
    permanentLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed); // 设置大小策略
    statusBar->addPermanentWidget(permanentLabel);

    // 连接退出动作
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);
}

mainwindow::~mainwindow()
{
}