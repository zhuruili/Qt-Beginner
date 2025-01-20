/********************************************************************************
** Form generated from reading UI file 'helloWorld.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOWORLD_H
#define UI_HELLOWORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloWorld
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helloWorld)
    {
        if (helloWorld->objectName().isEmpty())
            helloWorld->setObjectName("helloWorld");
        helloWorld->resize(800, 600);
        centralwidget = new QWidget(helloWorld);
        centralwidget->setObjectName("centralwidget");
        helloWorld->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helloWorld);
        menubar->setObjectName("menubar");
        helloWorld->setMenuBar(menubar);
        statusbar = new QStatusBar(helloWorld);
        statusbar->setObjectName("statusbar");
        helloWorld->setStatusBar(statusbar);

        retranslateUi(helloWorld);

        QMetaObject::connectSlotsByName(helloWorld);
    } // setupUi

    void retranslateUi(QMainWindow *helloWorld)
    {
        helloWorld->setWindowTitle(QCoreApplication::translate("helloWorld", "helloWorld", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helloWorld: public Ui_helloWorld {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOWORLD_H
