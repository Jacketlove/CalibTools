#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QDebug>
#include <QtGui>
#include <QtCore>

#include "camera.h"
#include "dialogsettiongcamera.h"
#include "motioncontrolfactory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Camera gigECamera;
    MotionControl *motionControl;
private slots:
    void on_actionOpenCamera_triggered();
    void on_pushButton_clicked();
    void on_actionCloseCamera_triggered();
    void on_actionConfigCamera_triggered();

    void on_actionSingleShot_triggered();

    void on_actionMotionControlOpen_triggered();

    void on_actionMotionControlClose_triggered();

protected:
    virtual void closeEvent (QCloseEvent *event);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
