#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/world.hpp"
#include "opencv2/opencv.hpp"
#include <QPainter>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void MainWindow::paintEvent(QPaintEvent *event);
        void MainWindow::cvmat2qimg(const cv::Mat *src, QImage *dst);
    private:
        Ui::MainWindow *ui;
        cv::VideoCapture cam;
        QPainter painter;


};

#endif // MAINWINDOW_H
