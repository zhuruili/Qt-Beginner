#pragma once
#include <QMainWindow>

class QSS : public QMainWindow
{
    Q_OBJECT

public:
    QSS(QWidget *parent = nullptr);
    ~QSS();

private slots:
    void changeTheme(int index);
};