#include "QtWidgets.h"

#include <QFont>
#include <QLabel>
#include <QFrame>
#include <QMovie>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QScrollBar>
#include <QSlider>
#include <QDial>
#include <QProgressDialog>
#include <QMessageBox>

QtWidgets::QtWidgets(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_QtWidgets)
{
    ui->setupUi(this); // 这是为Qt Designer生成的代码

    // 设置窗口大小
    this->resize(1280, 720);

    // QFont
    QFont font("华文行楷", 12, QFont::Bold); // 创建一个QFont对象
    font.setItalic(true);                    // 设置QFont的斜体

    // QLabel
    QLabel *label = new QLabel("这是一个标签", this);            // 创建一个QLabel对象
    label->setGeometry(QRect(QPoint(100, 100), QSize(100, 50))); // 设置QLabel的位置和大小
    label->setFont(font);                                        // 设置QLabel的字体

    // QFrame
    QFrame *frame = new QFrame(this);                            // 创建一个QFrame对象
    frame->setGeometry(QRect(QPoint(100, 200), QSize(100, 50))); // 设置QFrame的位置和大小
    frame->setFrameShape(QFrame::Box);                           // 设置QFrame的边框形状
    frame->setFrameShadow(QFrame::Sunken);                       // 设置QFrame的边框阴影
    frame->setLineWidth(2);                                      // 设置QFrame的边框宽度
    frame->setMidLineWidth(5);                                   // 设置QFrame的中间线宽度

    // QMovie
    /*
    注意：QMovie的构造函数中传入的文件路径并不是以当前VSCode工程目录为基准的
    另外，这里使用相对路径的方式直接导入文件，仅仅是为了验证此种方式的可行性
    在实际开发中，应该使用Qt资源文件（.qrc）的方式导入文件
    */
    QMovie *movie = new QMovie("../assets/Saki.gif"); // 创建一个QMovie对象
    QLabel *movieLabel = new QLabel(this);            // 创建一个QLabel对象
    movieLabel->setGeometry(QRect(QPoint(100, 300), QSize(422, 428)));
    movieLabel->setMovie(movie); // 设置QLabel的QMovie
    movie->start();              // 开始播放QMovie

    // QPushButton
    QPushButton *button = new QPushButton(tr("这是一个按钮"), this);
    button->setGeometry(QRect(QPoint(300, 100), QSize(100, 50)));

    // QDateTimeEdit
    QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    dateTimeEdit->setGeometry(QRect(QPoint(300, 200), QSize(200, 50)));
    dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss"); // 设置QDateTimeEdit的显示格式

    // QLineEdit
    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(QPoint(600, 100), QSize(200, 50)));
    lineEdit->setPlaceholderText("请输入文本"); // 设置QLineEdit的占位文本

    // QScrollBar
    QScrollBar *scrollBar = new QScrollBar(Qt::Horizontal, this);
    scrollBar->setGeometry(QRect(QPoint(600, 200), QSize(200, 50)));

    // QSlider
    QSlider *slider = new QSlider(Qt::Horizontal, this);
    slider->setGeometry(QRect(QPoint(600, 300), QSize(200, 50)));

    // QDial
    QDial *dial = new QDial(this);
    dial->setGeometry(QRect(QPoint(600, 400), QSize(200, 200)));

    // QProgressDialog
    QProgressDialog *progressDialog = new QProgressDialog(this);
    progressDialog->setGeometry(QRect(QPoint(800, 100), QSize(200, 50)));
    progressDialog->setMinimum(0);                // 设置QProgressDialog的最小值
    progressDialog->setMaximum(100);              // 设置QProgressDialog的最大值
    progressDialog->setValue(50);                 // 设置QProgressDialog的当前值
    progressDialog->setWindowTitle("进度对话框"); // 设置QProgressDialog的标题
    progressDialog->setLabelText("正在加载...");  // 设置QProgressDialog的文本
    progressDialog->setCancelButtonText("取消");  // 设置QProgressDialog的取消按钮文本
    // progressDialog->setAutoClose(true); // 设置QProgressDialog自动关闭
    // progressDialog->setAutoReset(true); // 设置QProgressDialog自动重置

    // QMessageBox
    QMessageBox::information(this, "提示", "这是一个消息框", QMessageBox::Ok);
    QMessageBox::question(this, "提示", "这是一个消息框", QMessageBox::Yes | QMessageBox::No);
    QMessageBox::warning(this, "警告", "这是一个消息框", QMessageBox::Ok);
    QMessageBox::critical(this, "错误", "这是一个消息框", QMessageBox::Ok);
    QMessageBox::about(this, "关于", "这是一个消息框");
    QMessageBox::aboutQt(this, "关于Qt"); // 真的是你呀
}

QtWidgets::~QtWidgets()
{
    delete ui;
}