#include "QSS.h"

#include <QApplication>
#include <QFile>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 从文件中加载样式表
    // QFile file(":/styles.qss");
    // file.open(QFile::ReadOnly);
    // QString styleSheet = QLatin1String(file.readAll());
    // a.setStyleSheet(styleSheet);
    // file.close();

    QSS w;
    w.show();
    return a.exec();
}