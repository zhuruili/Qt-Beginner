#include "MediaMetadata.h"

#include <QFile>
#include <QString>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QDebug>

// 构造函数
MediaMetadata::MediaMetadata(QObject *parent) : QObject(parent)
{
    connect(&player, &QMediaPlayer::metaDataChanged, this, &MediaMetadata::onMetaDataChanged);
}

// 从指定路径的媒体文件中提取元数据
void MediaMetadata::extractMetadata(const QString &filePath)
{
    player.setSource(QUrl::fromLocalFile(filePath)); // 设置媒体文件路径
}

// 元数据改变时的槽函数
void MediaMetadata::onMetaDataChanged()
{
    QMediaMetaData metaData = player.metaData();                       // 获取元数据
    title = metaData.stringValue(QMediaMetaData::Title);               // 获取标题信息
    artist = metaData.stringValue(QMediaMetaData::ContributingArtist); // 获取艺术家信息

    // Debug
    qDebug() << "Title: " << title;
    qDebug() << "Artist: " << artist;

    emit metadataUpdated(); // 发送元数据更新信号
}

// 获取媒体文件的标题
QString MediaMetadata::getTitle()
{
    return title;
}

// 获取媒体文件的艺术家信息
QString MediaMetadata::getArtist()
{
    return artist;
}