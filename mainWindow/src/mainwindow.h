#pragma once
#include <QMainWindow>

class mainwindow : public QMainWindow {
    Q_OBJECT

public:
    mainwindow(QWidget* parent = nullptr);
    ~mainwindow();
};