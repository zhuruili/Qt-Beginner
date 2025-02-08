#pragma once

#include <QString>
#include <QObject>
#include <QMediaPlayer>

class MediaMetadata : public QObject
{
    Q_OBJECT

public:
    MediaMetadata(QObject *parent = nullptr);
    void extractMetadata(const QString &filePath); // 根据文件路径提取元数据
    QString getTitle();
    QString getArtist();

signals:
    void metadataUpdated(); // 元数据更新信号

private slots:
    void onMetaDataChanged(); // 元数据改变时的槽函数

private:
    QString title;       // 存储媒体文件标题的变量
    QString artist;      // 存储媒体文件艺术家信息的变量
    QMediaPlayer player; // 媒体播放器实例
};