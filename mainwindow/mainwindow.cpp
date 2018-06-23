#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionOpenCamera->setEnabled(true);
    ui->actionCloseCamera->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenCamera_triggered()
{
    if( CAMERA_OK == gigECamera.Open() )
    {
        ui->actionOpenCamera->setEnabled(false);
        ui->actionCloseCamera->setEnabled(true);
    }
}

void MainWindow::on_actionCloseCamera_triggered()
{
    if( false == gigECamera.IsOpen() )
    {
        qDebug("camera has not opened");
        return;
    }
    gigECamera.Close();
    ui->actionOpenCamera->setEnabled(true);
    ui->actionCloseCamera->setEnabled(false);
    qDebug("close camera successful");
}

void MainWindow::on_pushButton_clicked()
{
    qDebug("on_pushButton_clicked");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if( true == gigECamera.IsOpen() )
    {
        gigECamera.Close();
        qDebug("close camera");
    }
    event->accept();
    exit(0);
}

void MainWindow::on_actionConfigCamera_triggered()
{
    DialogSettiongCamera *dialog = new DialogSettiongCamera(this);
    dialog->exec();
}

void MainWindow::on_actionSingleShot_triggered()
{
//    QPixmap qPixmap = gigECamera.ShotImageOne( );
//    qPixmap.save("abcd1.bmp");
    gigECamera.SaveImageOne(QString("1111111.bmp"));
//    ui->lblImage->setPixmap(qPixmap);
//    ui->lblImage->resize(ui->lblImage->pixmap()->size());
}
