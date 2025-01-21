#pragma once
#include "ui_QtLayouts.h"
#include <QMainWindow>

class QtLayouts : public QMainWindow {
    Q_OBJECT
    
public:
    QtLayouts(QWidget* parent = nullptr);
    ~QtLayouts();

private:
    Ui_QtLayouts* ui;
};