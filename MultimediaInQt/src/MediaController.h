#pragma once

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class MediaController : public QObject
{
    Q_OBJECT

public:
    explicit MediaController(QMediaPlayer *player, QObject *parent = nullptr);

    void loadMedia(const QString &filePath); // 加载媒体文件
    void playMedia();                        // 播放媒体文件
    void pauseMedia();                       // 暂停媒体播放
    void setPosition(qint64 position);       // 设置播放位置

private:
    QMediaPlayer *Player; // 媒体播放器实例
    QAudioOutput *audioOutput;
};