/********************************************************************************
** Form generated from reading UI file 'TextSearchApp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTSEARCHAPP_H
#define UI_TEXTSEARCHAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextSearchApp
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TextSearchApp)
    {
        if (TextSearchApp->objectName().isEmpty())
            TextSearchApp->setObjectName(QString::fromUtf8("TextSearchApp"));
        TextSearchApp->resize(800, 600);
        centralwidget = new QWidget(TextSearchApp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TextSearchApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TextSearchApp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        TextSearchApp->setMenuBar(menubar);
        statusbar = new QStatusBar(TextSearchApp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TextSearchApp->setStatusBar(statusbar);

        retranslateUi(TextSearchApp);

        QMetaObject::connectSlotsByName(TextSearchApp);
    } // setupUi

    void retranslateUi(QMainWindow *TextSearchApp)
    {
        TextSearchApp->setWindowTitle(QCoreApplication::translate("TextSearchApp", "TextSearchApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextSearchApp: public Ui_TextSearchApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTSEARCHAPP_H
