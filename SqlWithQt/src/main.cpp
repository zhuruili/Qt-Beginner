#include "SqlForQt.h"

#include <iostream>

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QDebug>
#pragma comment(lib, "user32.lib")

void initializeDatabase()
{
    // 链接到MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("pwd");

    if (!db.open())
    {
        std::cerr << "Cannot open database: "
                  << db.lastError().text().toStdString()
                  << std::endl;
        return;
    }

    QSqlQuery query;

    // 创建表
    if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), age INT)"))
    {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return;
    }
}

void operateDatabase()
{
    QSqlQuery query;

    // 插入数据
    if (!query.exec("INSERT INTO users (name, age) VALUES ('Alice', 30), ('Bob', 25), ('Charlie', 35)"))
    {
        qDebug() << "Failed to insert data:" << query.lastError().text();
        return;
    }

    // 查询数据
    if (!query.exec("SELECT * FROM users"))
    {
        qDebug() << "Failed to query data:" << query.lastError().text();
        return;
    }

    qDebug() << "Query results:";
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "ID:" << id << "Name:" << name << "Age:" << age;
    }

    // 更新数据
    if (!query.exec("UPDATE users SET age = 28 WHERE name = 'Bob'"))
    {
        qDebug() << "Failed to update data:" << query.lastError().text();
        return;
    }

    // 删除数据
    if (!query.exec("DELETE FROM users WHERE name = 'Charlie'"))
    {
        qDebug() << "Failed to delete data:" << query.lastError().text();
        return;
    }

    // 再次查询数据
    if (!query.exec("SELECT * FROM users"))
    {
        qDebug() << "Failed to query data:" << query.lastError().text();
        return;
    }

    qDebug() << "Query results after update and delete:";
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();
        qDebug() << "ID:" << id << "Name:" << name << "Age:" << age;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 打印支持的数据库驱动
    std::cout << "Available drivers:" << std::endl;
    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver, drivers)
    {
        std::cout << driver.toStdString() << std::endl;
    }

    initializeDatabase();
    operateDatabase();

    SqlForQt w;
    w.show();
    return a.exec();
}