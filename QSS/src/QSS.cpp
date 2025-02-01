#include "QSS.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>

QSS::QSS(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel("选择主题:", this);
    QComboBox *themeSelector = new QComboBox(this);
    themeSelector->addItem("Light");
    themeSelector->addItem("Dark");
    themeSelector->addItem("System");

    QPushButton *button1 = new QPushButton("Button 1", this);
    QPushButton *button2 = new QPushButton("Button 2", this);

    layout->addWidget(label);
    layout->addWidget(themeSelector);
    layout->addWidget(button1);
    layout->addWidget(button2);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // 连接主题选择器的信号到槽函数
    connect(themeSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &QSS::changeTheme);
}

QSS::~QSS()
{
}

void QSS::changeTheme(int index)
{
    QString styleSheet;
    switch (index)
    {
    case 0: // Light theme
        // 使用 R"()" 语法定义多行字符串，避免转义字符
        styleSheet = R"(
            /* 全局样式 */
            QWidget {
                background-color: #ffffff;
                color: #000000;
            }
            /* 按钮样式 */
            QPushButton {
                background-color: #f0f0f0;
                border: 1px solid #dcdcdc;
                padding: 5px;
            }
            /* 按钮悬停状态 */
            QPushButton:hover {
                background-color: #e0e0e0;
            }
            /* 按钮按下状态 */
            QPushButton:pressed {
                background-color: #d0d0d0;
            }
        )";
        break;
    case 1: // Dark theme
        styleSheet = R"(
            QWidget {
                background-color: #2e2e2e;
                color: #ffffff;
            }
            QPushButton {
                background-color: #3e3e3e;
                border: 1px solid #5e5e5e;
                padding: 5px;
            }
            QPushButton:hover {
                background-color: #4e4e4e;
            }
            QPushButton:pressed {
                background-color: #5e5e5e;
            }
        )";
        break;
    case 2:              // System theme
        styleSheet = ""; // 清空样式表，使用系统默认样式
        break;
    }
    qApp->setStyleSheet(styleSheet); // qApp 是一个全局指针，指向当前应用程序
}