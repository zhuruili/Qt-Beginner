#pragma once
#include "ui_helloWorld.h"
#include <QMainWindow>

class helloWorld : public QMainWindow {
    Q_OBJECT
    
public:
    helloWorld(QWidget* parent = nullptr);
    ~helloWorld();

private:
    Ui_helloWorld* ui;
};