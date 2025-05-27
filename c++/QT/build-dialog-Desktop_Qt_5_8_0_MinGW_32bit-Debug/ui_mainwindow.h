/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionModal;
    QAction *actionNonmodal;
    QAction *actionCriticial;
    QAction *actionWarning;
    QAction *actionInfo;
    QAction *actionQuestion;
    QAction *actionQFileDialog;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(643, 432);
        actionModal = new QAction(MainWindow);
        actionModal->setObjectName(QStringLiteral("actionModal"));
        actionNonmodal = new QAction(MainWindow);
        actionNonmodal->setObjectName(QStringLiteral("actionNonmodal"));
        actionCriticial = new QAction(MainWindow);
        actionCriticial->setObjectName(QStringLiteral("actionCriticial"));
        actionWarning = new QAction(MainWindow);
        actionWarning->setObjectName(QStringLiteral("actionWarning"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionQuestion = new QAction(MainWindow);
        actionQuestion->setObjectName(QStringLiteral("actionQuestion"));
        actionQFileDialog = new QAction(MainWindow);
        actionQFileDialog->setObjectName(QStringLiteral("actionQFileDialog"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 643, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionModal);
        menu->addAction(actionNonmodal);
        menu->addAction(actionCriticial);
        menu->addAction(actionWarning);
        menu->addAction(actionInfo);
        menu->addAction(actionQuestion);
        menu->addAction(actionQFileDialog);
        mainToolBar->addAction(actionModal);
        mainToolBar->addAction(actionNonmodal);
        mainToolBar->addAction(actionCriticial);
        mainToolBar->addAction(actionWarning);
        mainToolBar->addAction(actionInfo);
        mainToolBar->addAction(actionQuestion);
        mainToolBar->addAction(actionQFileDialog);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionModal->setText(QApplication::translate("MainWindow", "Modal", Q_NULLPTR));
        actionNonmodal->setText(QApplication::translate("MainWindow", "Nonmodal", Q_NULLPTR));
        actionCriticial->setText(QApplication::translate("MainWindow", "Criticial", Q_NULLPTR));
        actionWarning->setText(QApplication::translate("MainWindow", "Warning", Q_NULLPTR));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
        actionQuestion->setText(QApplication::translate("MainWindow", "Question", Q_NULLPTR));
        actionQFileDialog->setText(QApplication::translate("MainWindow", "QFileDialog", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
