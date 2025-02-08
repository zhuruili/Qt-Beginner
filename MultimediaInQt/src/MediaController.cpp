#include "MediaController.h"

#include <QMediaPlayer>

MediaController::MediaController()
{
    mediaPlayer = new QMediaPlayer;
}

void MediaController::loadMedia(const QString &filePath)
{
    mediaPlayer->setSource(QUrl::fromLocalFile(filePath)); // Load media file
}

void MediaController::playMedia()
{
    mediaPlayer->play(); // Start playback
}

void MediaController::pauseMedia()
{
    mediaPlayer->pause(); // Pause playback
}

void MediaController::setPosition(qint64 position)
{
    mediaPlayer->setPosition(position); // Set playback position
}