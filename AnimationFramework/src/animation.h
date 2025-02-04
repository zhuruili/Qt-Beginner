#pragma once
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QPushButton>

class animation : public QMainWindow
{
    Q_OBJECT

public:
    animation(QWidget *parent = nullptr);
    ~animation();

private:
    QPushButton *button;
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
    QSequentialAnimationGroup *sequentialGroup;
    QParallelAnimationGroup *parallelGroup;
};