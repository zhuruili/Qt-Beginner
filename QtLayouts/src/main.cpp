#include "QtLayouts.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建一个主窗口部件
    QWidget window;
    window.setWindowTitle("Qt Layouts Example");

    // 创建垂直布局管理器
    QVBoxLayout *vLayout = new QVBoxLayout;

    // 创建一些按钮并添加到垂直布局中
    QPushButton *button1 = new QPushButton("Button 1");
    QPushButton *button2 = new QPushButton("Button 2");
    QPushButton *button3 = new QPushButton("Button 3");

    vLayout->addWidget(button1);
    vLayout->addWidget(button2);
    vLayout->addWidget(button3);

    // 创建水平布局管理器
    QHBoxLayout *hLayout = new QHBoxLayout;

    // 创建一些按钮并添加到水平布局中
    QPushButton *button4 = new QPushButton("Button 4");
    QPushButton *button5 = new QPushButton("Button 5");

    hLayout->addWidget(button4);
    hLayout->addWidget(button5);

    // 将水平布局添加到垂直布局中
    vLayout->addLayout(hLayout);

    // 创建网格布局管理器
    QGridLayout *gridLayout = new QGridLayout;

    // 创建一些按钮并添加到网格布局中
    QPushButton *button6 = new QPushButton("Button 6");
    QPushButton *button7 = new QPushButton("Button 7");
    QPushButton *button8 = new QPushButton("Button 8");
    QPushButton *button9 = new QPushButton("Button 9");

    gridLayout->addWidget(button6, 0, 0); // 第一行第一列
    gridLayout->addWidget(button7, 0, 1); // 第一行第二列
    gridLayout->addWidget(button8, 1, 0); // 第二行第一列
    gridLayout->addWidget(button9, 1, 1); // 第二行第二列

    // 将网格布局添加到垂直布局中
    vLayout->addLayout(gridLayout);

    // 将布局设置到主窗口部件
    window.setLayout(vLayout);

    // 显示窗口
    window.show();

    return app.exec();
}