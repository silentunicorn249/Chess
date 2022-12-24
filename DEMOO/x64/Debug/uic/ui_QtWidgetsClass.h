/********************************************************************************
** Form generated from reading UI file 'QtWidgetsClass.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSCLASS_H
#define UI_QTWIDGETSCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsClassClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsClassClass)
    {
        if (QtWidgetsClassClass->objectName().isEmpty())
            QtWidgetsClassClass->setObjectName("QtWidgetsClassClass");
        QtWidgetsClassClass->resize(600, 400);
        menuBar = new QMenuBar(QtWidgetsClassClass);
        menuBar->setObjectName("menuBar");
        QtWidgetsClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsClassClass);
        mainToolBar->setObjectName("mainToolBar");
        QtWidgetsClassClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtWidgetsClassClass);
        centralWidget->setObjectName("centralWidget");
        QtWidgetsClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtWidgetsClassClass);
        statusBar->setObjectName("statusBar");
        QtWidgetsClassClass->setStatusBar(statusBar);

        retranslateUi(QtWidgetsClassClass);

        QMetaObject::connectSlotsByName(QtWidgetsClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsClassClass)
    {
        QtWidgetsClassClass->setWindowTitle(QCoreApplication::translate("QtWidgetsClassClass", "QtWidgetsClass", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsClassClass: public Ui_QtWidgetsClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSCLASS_H
