#pragma once
#include "ui_SignalSlot.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class SignalSlot : public QMainWindow
{
    Q_OBJECT

public:
    SignalSlot(QWidget *parent = nullptr);
    ~SignalSlot();

signals:
    // 自定义信号
    void textChanged(const QString &newText);

private slots:
    // 槽函数声明
    void onButtonClicked();
    void onTextChanged(const QString &newText);

private:
    Ui_SignalSlot *ui;
    QPushButton *button;
    QLabel *label;
    QLineEdit *lineEdit;
};