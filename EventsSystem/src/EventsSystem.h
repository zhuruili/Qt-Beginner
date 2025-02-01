#pragma once
#include <QMainWindow>

class EventsSystem : public QMainWindow
{
    Q_OBJECT

public:
    EventsSystem(QWidget *parent = nullptr);
    ~EventsSystem();

protected:
    // 重载事件处理函数
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};