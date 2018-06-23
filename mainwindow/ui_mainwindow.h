/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenCamera;
    QAction *actionCloseCamera;
    QAction *actionConfigCamera;
    QAction *actionSingleShot;
    QWidget *centralWidget;
    QLabel *lblImage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(639, 536);
        actionOpenCamera = new QAction(MainWindow);
        actionOpenCamera->setObjectName(QStringLiteral("actionOpenCamera"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/action/icons/\347\233\270\346\234\272\351\273\204.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/action/icons/\347\233\270\346\234\272\347\273\277.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpenCamera->setIcon(icon);
        actionCloseCamera = new QAction(MainWindow);
        actionCloseCamera->setObjectName(QStringLiteral("actionCloseCamera"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/action/icons/\347\233\270\346\234\272\347\273\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCloseCamera->setIcon(icon1);
        actionConfigCamera = new QAction(MainWindow);
        actionConfigCamera->setObjectName(QStringLiteral("actionConfigCamera"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/action/icons/settings_32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigCamera->setIcon(icon2);
        actionSingleShot = new QAction(MainWindow);
        actionSingleShot->setObjectName(QStringLiteral("actionSingleShot"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/action/icons/OneShot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSingleShot->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lblImage = new QLabel(centralWidget);
        lblImage->setObjectName(QStringLiteral("lblImage"));
        lblImage->setGeometry(QRect(10, 10, 611, 451));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 639, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionOpenCamera);
        mainToolBar->addAction(actionCloseCamera);
        mainToolBar->addAction(actionConfigCamera);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSingleShot);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpenCamera->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpenCamera->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionCloseCamera->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\347\233\270\346\234\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCloseCamera->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        actionConfigCamera->setText(QApplication::translate("MainWindow", "\347\233\270\346\234\272\351\205\215\347\275\256", nullptr));
        actionSingleShot->setText(QApplication::translate("MainWindow", "\346\213\215\346\221\204\345\215\225\345\274\240", nullptr));
        lblImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
