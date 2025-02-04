#include "animation.h"
#include <QVBoxLayout>
#include <QEasingCurve>

animation::animation(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口大小
    setFixedSize(320, 50);

    button = new QPushButton("Animate Me", this);
    button->setGeometry(10, 10, 100, 30);

    // 创建属性动画
    animation1 = new QPropertyAnimation(button, "geometry");
    animation1->setDuration(1000);                       // 1 秒
    animation1->setStartValue(QRect(10, 10, 100, 30));   // 开始位置
    animation1->setEndValue(QRect(200, 10, 100, 30));    // 结束位置
    animation1->setEasingCurve(QEasingCurve::OutBounce); // 缓动效果（弹跳效果）

    animation2 = new QPropertyAnimation(button, "geometry");
    animation2->setDuration(1000);
    animation2->setStartValue(QRect(200, 10, 100, 30));
    animation2->setEndValue(QRect(10, 10, 100, 30));
    animation2->setEasingCurve(QEasingCurve::InOutQuad); // 缓动效果（缓入缓出）

    // 创建顺序动画组
    sequentialGroup = new QSequentialAnimationGroup(this);
    sequentialGroup->addAnimation(animation1);
    sequentialGroup->addAnimation(animation2);

    // 连接按钮点击事件以启动动画
    connect(button, &QPushButton::clicked, this,
            [this]()
            {
                sequentialGroup->start();
            });
}

animation::~animation()
{
}