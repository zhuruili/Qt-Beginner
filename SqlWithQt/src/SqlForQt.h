#pragma once
#include <QMainWindow>

class SqlForQt : public QMainWindow {
    Q_OBJECT

public:
    SqlForQt(QWidget* parent = nullptr);
    ~SqlForQt();
};