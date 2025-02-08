#include "MediaController.h"

#include <QMediaPlayer>
#include <QDebug>

MediaController::MediaController(QMediaPlayer *player, QObject *parent)
    : QObject(parent), Player(player)
{
    audioOutput = new QAudioOutput;
    Player->setAudioOutput(audioOutput); // 这一行代码非常容易忘，如果没加上这一行代码是不会报错的，但是你会发现你不管怎么操作都不会有声音
}

void MediaController::loadMedia(const QString &filePath)
{
    Player->setSource(QUrl::fromLocalFile(filePath)); // 加载媒体文件
}

void MediaController::playMedia()
{
    Player->play(); // 开始播放
}

void MediaController::pauseMedia()
{
    Player->pause(); // 暂停播放
}

void MediaController::setPosition(qint64 position)
{
    Player->setPosition(position); // 设置播放位置
}