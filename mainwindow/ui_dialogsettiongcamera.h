/********************************************************************************
** Form generated from reading UI file 'dialogsettiongcamera.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETTIONGCAMERA_H
#define UI_DIALOGSETTIONGCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSettiongCamera
{
public:
    QFrame *frame;
    QLabel *label;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_14;
    QLineEdit *exposureTime;
    QLabel *label_6;
    QLineEdit *fps;
    QComboBox *imageFormat;
    QLabel *label_18;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *lineEditFilePath;
    QLineEdit *image2save;
    QLabel *label_15;
    QLabel *label_4;
    QLineEdit *lineEditFilePrefix;
    QLabel *label_2;
    QLabel *label_11;
    QLabel *label_13;
    QPushButton *selectDir;
    QLineEdit *lineEditHeight;
    QLabel *label_19;
    QLineEdit *lineEditWidth;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConfirm;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;

    void setupUi(QDialog *DialogSettiongCamera)
    {
        if (DialogSettiongCamera->objectName().isEmpty())
            DialogSettiongCamera->setObjectName(QStringLiteral("DialogSettiongCamera"));
        DialogSettiongCamera->resize(495, 379);
        frame = new QFrame(DialogSettiongCamera);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 30, 411, 271));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 351, 20));
        label->setAlignment(Qt::AlignCenter);
        formLayoutWidget = new QWidget(frame);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 381, 221));
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(formLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 6, 5, 1, 1);

        exposureTime = new QLineEdit(formLayoutWidget);
        exposureTime->setObjectName(QStringLiteral("exposureTime"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exposureTime->sizePolicy().hasHeightForWidth());
        exposureTime->setSizePolicy(sizePolicy);

        gridLayout->addWidget(exposureTime, 6, 4, 1, 1);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        fps = new QLineEdit(formLayoutWidget);
        fps->setObjectName(QStringLiteral("fps"));
        sizePolicy.setHeightForWidth(fps->sizePolicy().hasHeightForWidth());
        fps->setSizePolicy(sizePolicy);

        gridLayout->addWidget(fps, 5, 4, 1, 1);

        imageFormat = new QComboBox(formLayoutWidget);
        imageFormat->addItem(QString());
        imageFormat->setObjectName(QStringLiteral("imageFormat"));

        gridLayout->addWidget(imageFormat, 0, 5, 1, 1);

        label_18 = new QLabel(formLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_18, 2, 0, 1, 1);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEditFilePath = new QLineEdit(formLayoutWidget);
        lineEditFilePath->setObjectName(QStringLiteral("lineEditFilePath"));
        sizePolicy.setHeightForWidth(lineEditFilePath->sizePolicy().hasHeightForWidth());
        lineEditFilePath->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEditFilePath, 1, 4, 1, 1);

        image2save = new QLineEdit(formLayoutWidget);
        image2save->setObjectName(QStringLiteral("image2save"));
        sizePolicy.setHeightForWidth(image2save->sizePolicy().hasHeightForWidth());
        image2save->setSizePolicy(sizePolicy);

        gridLayout->addWidget(image2save, 4, 4, 1, 1);

        label_15 = new QLabel(formLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 5, 5, 1, 1);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lineEditFilePrefix = new QLineEdit(formLayoutWidget);
        lineEditFilePrefix->setObjectName(QStringLiteral("lineEditFilePrefix"));
        sizePolicy.setHeightForWidth(lineEditFilePrefix->sizePolicy().hasHeightForWidth());
        lineEditFilePrefix->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEditFilePrefix, 0, 4, 1, 1);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 7, 1, 1, 1);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 4, 5, 1, 1);

        selectDir = new QPushButton(formLayoutWidget);
        selectDir->setObjectName(QStringLiteral("selectDir"));

        gridLayout->addWidget(selectDir, 1, 5, 1, 1);

        lineEditHeight = new QLineEdit(formLayoutWidget);
        lineEditHeight->setObjectName(QStringLiteral("lineEditHeight"));

        gridLayout->addWidget(lineEditHeight, 2, 4, 1, 1);

        label_19 = new QLabel(formLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(16777215, 17));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_19, 3, 0, 1, 1);

        lineEditWidth = new QLineEdit(formLayoutWidget);
        lineEditWidth->setObjectName(QStringLiteral("lineEditWidth"));

        gridLayout->addWidget(lineEditWidth, 3, 4, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        widget = new QWidget(DialogSettiongCamera);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(250, 330, 181, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnConfirm = new QPushButton(widget);
        btnConfirm->setObjectName(QStringLiteral("btnConfirm"));

        horizontalLayout->addWidget(btnConfirm);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        retranslateUi(DialogSettiongCamera);

        QMetaObject::connectSlotsByName(DialogSettiongCamera);
    } // setupUi

    void retranslateUi(QDialog *DialogSettiongCamera)
    {
        DialogSettiongCamera->setWindowTitle(QApplication::translate("DialogSettiongCamera", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogSettiongCamera", "\347\233\270\346\234\272\350\256\276\347\275\256", nullptr));
        label_14->setText(QApplication::translate("DialogSettiongCamera", "us", nullptr));
        label_6->setText(QApplication::translate("DialogSettiongCamera", "\346\233\235\345\205\211\346\227\266\351\227\264", nullptr));
        imageFormat->setItemText(0, QApplication::translate("DialogSettiongCamera", "bmp", nullptr));

        label_18->setText(QApplication::translate("DialogSettiongCamera", "\351\253\230\345\272\246", nullptr));
        label_5->setText(QApplication::translate("DialogSettiongCamera", "\345\270\247\351\242\221", nullptr));
        label_3->setText(QApplication::translate("DialogSettiongCamera", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        lineEditFilePath->setText(QApplication::translate("DialogSettiongCamera", "/Users/aihe/images", nullptr));
        image2save->setText(QApplication::translate("DialogSettiongCamera", "200", nullptr));
        label_15->setText(QApplication::translate("DialogSettiongCamera", "fps", nullptr));
        label_4->setText(QApplication::translate("DialogSettiongCamera", "\351\207\207\351\233\206\346\225\260\351\207\217", nullptr));
        lineEditFilePrefix->setText(QApplication::translate("DialogSettiongCamera", "capture", nullptr));
        label_2->setText(QApplication::translate("DialogSettiongCamera", "\346\226\207\344\273\266\345\220\215\345\211\215\347\274\200", nullptr));
        label_11->setText(QString());
        label_13->setText(QApplication::translate("DialogSettiongCamera", "\345\274\240", nullptr));
        selectDir->setText(QApplication::translate("DialogSettiongCamera", "...", nullptr));
        label_19->setText(QApplication::translate("DialogSettiongCamera", "\345\256\275\345\272\246", nullptr));
        btnConfirm->setText(QApplication::translate("DialogSettiongCamera", "\347\241\256\350\256\244", nullptr));
        btnCancel->setText(QApplication::translate("DialogSettiongCamera", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSettiongCamera: public Ui_DialogSettiongCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETTIONGCAMERA_H
