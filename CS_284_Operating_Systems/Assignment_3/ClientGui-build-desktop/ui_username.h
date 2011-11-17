/********************************************************************************
** Form generated from reading UI file 'username.ui'
**
** Created: Thu Nov 17 11:44:02 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERNAME_H
#define UI_USERNAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Username
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Username)
    {
        if (Username->objectName().isEmpty())
            Username->setObjectName(QString::fromUtf8("Username"));
        Username->resize(318, 81);
        widget = new QWidget(Username);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 301, 62));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(Username);
        QObject::connect(buttonBox, SIGNAL(accepted()), Username, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Username, SLOT(reject()));

        QMetaObject::connectSlotsByName(Username);
    } // setupUi

    void retranslateUi(QDialog *Username)
    {
        Username->setWindowTitle(QApplication::translate("Username", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Username", "Please Enter Username", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Username: public Ui_Username {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERNAME_H
