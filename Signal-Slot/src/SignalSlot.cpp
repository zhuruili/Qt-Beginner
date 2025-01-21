#include "SignalSlot.h"

SignalSlot::SignalSlot(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SignalSlot)
{
    ui->setupUi(this);

    // 创建一个按钮
    button = new QPushButton("Click Me", this);
    button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

    // 创建一个标签
    label = new QLabel("Hello, World!", this);
    label->setGeometry(QRect(QPoint(100, 200), QSize(200, 50)));

    // 创建一个文本输入框
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(QPoint(100, 300), QSize(200, 50)));

    // 连接按钮的点击信号到槽函数
    connect(button, &QPushButton::clicked, this, &SignalSlot::onButtonClicked);

    // 连接文本输入框的文本变化信号到槽函数
    connect(lineEdit, &QLineEdit::textChanged, this, &SignalSlot::onTextChanged);

    // 连接自定义信号到槽函数
    connect(this, &SignalSlot::textChanged, this, &SignalSlot::onTextChanged);
}

SignalSlot::~SignalSlot()
{
    delete ui;
}

// 槽函数定义
void SignalSlot::onButtonClicked()
{
    // 当按钮被点击时，改变标签的文本
    label->setText("Button Clicked!");
}

// 槽函数定义
void SignalSlot::onTextChanged(const QString &newText)
{
    // 当文本输入框的文本变化时，改变标签的文本
    label->setText(newText);
}