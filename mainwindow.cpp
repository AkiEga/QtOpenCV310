#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cam = cv::VideoCapture(0);    
    cv::Mat test_frame;
    cam >> test_frame;   

    // set window size
    int win_margin=50;
    QSize win_sz(test_frame.cols + win_margin,  test_frame.rows + win_margin);
    setWindowTitle(tr("Draw by OpenCV on QWidget"));
    resize(win_sz);

    // set window refresh interval
    QTimer *timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    float win_fps=60;
    timer->start(1000/win_fps);
}

void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    cv::Mat src, dst;
    cam >> src;

    // cv::Mat -> QImage
    cv::cvtColor(src, dst, CV_RGB2BGR);
    QImage cam_frame_qimg((uchar *)dst.data, dst.cols, dst.rows,(int)dst.step, QImage::Format_RGB888);

    // set painter
    QPainter painter(this);

    // refresh image
    QPoint draw_point(25,25);
    painter.drawImage(draw_point,cam_frame_qimg);

    return;
}

MainWindow::~MainWindow()
{
    cam.release();
    delete ui;
}
