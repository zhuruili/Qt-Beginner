#pragma once

#include <QMediaPlayer>
#include <QString>

class MediaController
{
public:
    MediaController();                       // 构造函数
    void loadMedia(const QString &filePath); // 加载指定路径的媒体文件
    void playMedia();                        // 播放媒体文件
    void pauseMedia();                       // 暂停媒体播放
    void setPosition(qint64 position);       // 设置播放进度

private:
    QMediaPlayer *mediaPlayer;
};