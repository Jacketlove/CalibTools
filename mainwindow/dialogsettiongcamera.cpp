#include "dialogsettiongcamera.h"
#include "ui_dialogsettiongcamera.h"

DialogSettiongCamera::DialogSettiongCamera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettiongCamera)
{
    ui->setupUi(this);
    MainWindow *pmainWindow = (MainWindow*) parentWidget();  //获取父窗口指针
    ui->lineEditFilePrefix->setText(pmainWindow->gigECamera.GetFilePrefix());
    ui->lineEditFilePath->setText(pmainWindow->gigECamera.GetFilePath());
    ui->lineEditWidth->setText(QString::number(pmainWindow->gigECamera.GetWidth(), 10, 0));
    ui->lineEditHeight->setText(QString::number(pmainWindow->gigECamera.GetHeight(), 10, 0));
    ui->exposureTime->setText(QString::number(pmainWindow->gigECamera.GetExposureTime(), 10, 0));
}

DialogSettiongCamera::~DialogSettiongCamera()
{
    delete ui;
}

void DialogSettiongCamera::on_selectDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("打开目录"),
                                                 QDir::homePath(),
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    ui->lineEditFilePath->setText(dir);
}

void DialogSettiongCamera::on_btnConfirm_clicked()
{
    MainWindow *pmainWindow = (MainWindow*) parentWidget();  //获取父窗口指针
    pmainWindow->gigECamera.SetFilePath( ui->lineEditFilePrefix->text() );
    pmainWindow->gigECamera.SetFilePrefix( ui->lineEditFilePath->text() );
    pmainWindow->gigECamera.SetHeight( ui->lineEditHeight->text().toLongLong() );
    pmainWindow->gigECamera.SetWidth( ui->lineEditWidth->text().toLongLong() );
    pmainWindow->gigECamera.SetExposureTime( ui->exposureTime->text().toDouble() );
}

void DialogSettiongCamera::on_btnCancel_clicked()
{

}
