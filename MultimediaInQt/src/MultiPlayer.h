#pragma once

#include <QMainWindow>
#include <QMediaPlayer>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include "MediaController.h"
#include "MediaMetadata.h"

class MultiPlayer : public QMainWindow
{
    Q_OBJECT

public:
    MultiPlayer(QWidget *parent = nullptr);
    ~MultiPlayer();

    void openMediaFile();                // Open file dialog to select media file
    void updateProgressBar();            // Update progress bar with current playback position
    void loadMetadata(QString filepath); // Read and display media file metadata

private:
    QMediaPlayer *mediaPlayer;        // 媒体播放器实例
    QLabel *metadataLabel;            // 显示元数据的标签
    QPushButton *playButton;          // 播放按钮
    QPushButton *pauseButton;         // 暂停按钮
    QSlider *slider;                  // 播放进度滑块
    MediaController *mediaController; // 媒体操作控制器
    MediaMetadata *mediaMetadata;     // 媒体文件元数据处理器
};