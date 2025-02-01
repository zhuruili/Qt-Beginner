#include "EventsSystem.h"

#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QTimerEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QPainter>

EventsSystem::EventsSystem(QWidget *parent)
    : QMainWindow(parent)
{
    setAcceptDrops(true); // 允许拖放操作
    startTimer(10000);    // 每10秒触发一次定时器事件

    // 设置窗口属性
    setWindowTitle("Qt 事件系统示例");
    setFixedSize(400, 300);
    setMouseTracking(true); // 开启鼠标追踪
}

EventsSystem::~EventsSystem()
{
}

// 鼠标按下事件处理
void EventsSystem::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QMessageBox::information(this, "鼠标事件", "左键按下");
    }
}

// 滚轮事件处理
void EventsSystem::wheelEvent(QWheelEvent *event)
{
    int delta = event->angleDelta().y();
    QMessageBox::information(this, "滚轮事件", QString("滚轮滚动: %1").arg(delta));
}

// 键盘按下事件处理
void EventsSystem::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        close(); // 按下Esc键关闭窗口
    }
    else
    {
        QMessageBox::information(this, "键盘事件", QString("按下键: %1").arg(event->text()));
    }
}

// 定时器事件处理
void EventsSystem::timerEvent(QTimerEvent *event)
{
    int randomValue = QRandomGenerator::global()->bounded(100);
    QMessageBox::information(this, "定时器事件", QString("随机数: %1").arg(randomValue));
}

// 拖放进入事件处理
void EventsSystem::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText())
    {
        event->acceptProposedAction();
    }
}

// 拖放事件处理
void EventsSystem::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasText())
    {
        QString text = event->mimeData()->text();
        QMessageBox::information(this, "拖放事件", QString("拖放内容: %1").arg(text));
    }
}

// 绘制事件处理
void EventsSystem::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Qt 事件系统示例");
}