#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"hello qDebug!\n";
    src = new cv::Mat(10,10,CV_8UC3,cv::Scalar(0,0,255));

    qDebug()<<"hello OpenCV cv::Mat src("<<src->rows <<","<< src->cols << ")";
}

MainWindow::~MainWindow()
{
    delete ui;
}
