/********************************************************************************
** Form generated from reading UI file 'image.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_H
#define UI_IMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *imageClass)
    {
        if (imageClass->objectName().isEmpty())
            imageClass->setObjectName(QStringLiteral("imageClass"));
        imageClass->resize(600, 400);
        menuBar = new QMenuBar(imageClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        imageClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(imageClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        imageClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(imageClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imageClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(imageClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        imageClass->setStatusBar(statusBar);

        retranslateUi(imageClass);

        QMetaObject::connectSlotsByName(imageClass);
    } // setupUi

    void retranslateUi(QMainWindow *imageClass)
    {
        imageClass->setWindowTitle(QApplication::translate("imageClass", "image", 0));
    } // retranslateUi

};

namespace Ui {
    class imageClass: public Ui_imageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_H
