#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"hello qDebug!\n";
}

MainWindow::~MainWindow()
{
    delete ui;
}
