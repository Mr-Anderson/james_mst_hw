/********************************************************************************
** Form generated from reading UI file 'clientgui.ui'
**
** Created: Thu Nov 17 11:44:02 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTGUI_H
#define UI_CLIENTGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientGui
{
public:
    QAction *actionUsername;
    QAction *actionExit;
    QAction *actionCange_User;
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QMenu *menuChat_Client;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientGui)
    {
        if (ClientGui->objectName().isEmpty())
            ClientGui->setObjectName(QString::fromUtf8("ClientGui"));
        ClientGui->resize(292, 321);
        actionUsername = new QAction(ClientGui);
        actionUsername->setObjectName(QString::fromUtf8("actionUsername"));
        actionExit = new QAction(ClientGui);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCange_User = new QAction(ClientGui);
        actionCange_User->setObjectName(QString::fromUtf8("actionCange_User"));
        centralWidget = new QWidget(ClientGui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 271, 251));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        ClientGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClientGui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 292, 25));
        menuChat_Client = new QMenu(menuBar);
        menuChat_Client->setObjectName(QString::fromUtf8("menuChat_Client"));
        ClientGui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClientGui);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ClientGui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClientGui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ClientGui->setStatusBar(statusBar);

        menuBar->addAction(menuChat_Client->menuAction());
        menuChat_Client->addAction(actionCange_User);
        menuChat_Client->addAction(actionExit);

        retranslateUi(ClientGui);

        QMetaObject::connectSlotsByName(ClientGui);
    } // setupUi

    void retranslateUi(QMainWindow *ClientGui)
    {
        ClientGui->setWindowTitle(QApplication::translate("ClientGui", "ClientGui", 0, QApplication::UnicodeUTF8));
        actionUsername->setText(QApplication::translate("ClientGui", "Username", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("ClientGui", "Exit", 0, QApplication::UnicodeUTF8));
        actionCange_User->setText(QApplication::translate("ClientGui", "Cange User", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ClientGui", "Message", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("ClientGui", "Send", 0, QApplication::UnicodeUTF8));
        menuChat_Client->setTitle(QApplication::translate("ClientGui", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientGui: public Ui_ClientGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTGUI_H
