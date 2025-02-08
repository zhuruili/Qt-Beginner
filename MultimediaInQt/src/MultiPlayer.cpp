#include "MultiPlayer.h"

#include <QFileDialog>
#include <QMediaPlayer>
#include <QProgressBar>
#include <QLabel>
#include <QSlider>
#include <QTime>

MultiPlayer::MultiPlayer(QWidget *parent)
    : QMainWindow(parent),
      mediaPlayer(new QMediaPlayer(this)),
      playButton(new QPushButton("Play", this)),
      pauseButton(new QPushButton("Pause", this)),
      mediaMetadata(new MediaMetadata()),
      metadataLabel(new QLabel("暂无媒体播放", this)),
      slider(new QSlider(Qt::Horizontal, this)),
      mediaController(new MediaController(mediaPlayer, this))
{
    // 主窗口参数设置
    setWindowTitle("Multimedia Player");
    resize(300, 250);

    QPushButton *openButton = new QPushButton("Select File", this); // 文件选择按钮
    // 点击按钮，打开文件选择对话框
    connect(openButton, &QPushButton::clicked, this, &MultiPlayer::openMediaFile);

    // 加入布局
    QHBoxLayout *FileLayout = new QHBoxLayout;
    FileLayout->addWidget(metadataLabel);
    FileLayout->addWidget(openButton);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(FileLayout);
    layout->addWidget(slider);
    QHBoxLayout *PlayAndPauseLayout = new QHBoxLayout;
    PlayAndPauseLayout->addWidget(playButton);
    PlayAndPauseLayout->addWidget(pauseButton);
    layout->addLayout(PlayAndPauseLayout);

    // 中心组件
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // 其他信号和槽连接
    connect(mediaMetadata, &MediaMetadata::metadataUpdated, this, [this]()
            { metadataLabel->setText(mediaMetadata->getTitle() + " - " + mediaMetadata->getArtist()); }); // 更新元数据
    connect(playButton, &QPushButton::clicked, mediaController, &MediaController::playMedia);             // 播放歌曲
    connect(pauseButton, &QPushButton::clicked, mediaController, &MediaController::pauseMedia);           // 暂停歌曲
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &MultiPlayer::updateProgressBar);          // 更新进度条
}

MultiPlayer::~MultiPlayer()
{
}

void MultiPlayer::openMediaFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Media File", "", "Media Files (*.mp3 *.mp4 *.wav *.avi)"); // 打开文件对话框，选择媒体文件
    if (!filePath.isEmpty())
    {
        mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
        mediaController->loadMedia(filePath);
        loadMetadata(filePath);
    }
}

void MultiPlayer::updateProgressBar()
{
    if (mediaPlayer->duration() > 0)
    {
        slider->setValue(static_cast<int>((mediaPlayer->position() * 100) / mediaPlayer->duration())); // Convert to seconds for slider
    }
}

void MultiPlayer::loadMetadata(QString filepath)
{
    mediaMetadata->extractMetadata(filepath); // 提取元数据
}