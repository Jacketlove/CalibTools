#ifndef DIALOGSETTIONGCAMERA_H
#define DIALOGSETTIONGCAMERA_H

#include "camera.h"
#include "mainwindow.h"
#include <QDialog>
#include <QFileDialog>

namespace Ui {
class DialogSettiongCamera;
}

class DialogSettiongCamera : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSettiongCamera(QWidget *parent = 0);
    ~DialogSettiongCamera();

private slots:
    void on_selectDir_clicked();

    void on_btnConfirm_clicked();

    void on_btnCancel_clicked();

private:
    Ui::DialogSettiongCamera *ui;

};

#endif // DIALOGSETTIONGCAMERA_H
