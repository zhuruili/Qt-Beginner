#pragma once
#include "ui_QtWidgets.h"
#include <QMainWindow>

class QtWidgets : public QMainWindow {
    Q_OBJECT
    
public:
    QtWidgets(QWidget* parent = nullptr);
    ~QtWidgets();

private:
    Ui_QtWidgets* ui;
};