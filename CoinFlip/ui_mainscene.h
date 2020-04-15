/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSence
{
public:
    QAction *actionQuit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuStart;

    void setupUi(QMainWindow *MainSence)
    {
        if (MainSence->objectName().isEmpty())
            MainSence->setObjectName(QStringLiteral("MainSence"));
        MainSence->resize(320, 588);
        actionQuit = new QAction(MainSence);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionAbout = new QAction(MainSence);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralwidget = new QWidget(MainSence);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainSence->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainSence);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 320, 29));
        menuStart = new QMenu(menubar);
        menuStart->setObjectName(QStringLiteral("menuStart"));
        MainSence->setMenuBar(menubar);

        menubar->addAction(menuStart->menuAction());
        menuStart->addAction(actionQuit);
        menuStart->addSeparator();
        menuStart->addAction(actionAbout);

        retranslateUi(MainSence);

        QMetaObject::connectSlotsByName(MainSence);
    } // setupUi

    void retranslateUi(QMainWindow *MainSence)
    {
        MainSence->setWindowTitle(QApplication::translate("MainSence", "MainSence", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainSence", "\351\200\200\345\207\272", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainSence", "\345\205\263\344\272\216", Q_NULLPTR));
        menuStart->setTitle(QApplication::translate("MainSence", "\350\217\234\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainSence: public Ui_MainSence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
