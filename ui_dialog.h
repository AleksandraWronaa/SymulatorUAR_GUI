/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QSplitter *splitter_5;
    QLabel *label_4;
    QSplitter *splitter_4;
    QSplitter *splitter;
    QLabel *label_3;
    QDoubleSpinBox *szumDialog;
    QSpinBox *spinbox_delay;
    QSplitter *splitter_2;
    QLabel *label;
    QLineEdit *ADialog;
    QSplitter *splitter_3;
    QLabel *label_2;
    QLineEdit *BDialog;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        splitter_5 = new QSplitter(Dialog);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setGeometry(QRect(70, 50, 241, 141));
        splitter_5->setOrientation(Qt::Vertical);
        label_4 = new QLabel(splitter_5);
        label_4->setObjectName("label_4");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_4->setFont(font);
        splitter_5->addWidget(label_4);
        splitter_4 = new QSplitter(splitter_5);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_4);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter);
        label_3->setObjectName("label_3");
        splitter->addWidget(label_3);
        szumDialog = new QDoubleSpinBox(splitter);
        szumDialog->setObjectName("szumDialog");
        splitter->addWidget(szumDialog);
        splitter_4->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_2);
        label->setObjectName("label");
        splitter_2->addWidget(label);
        ADialog = new QLineEdit(splitter_2);
        ADialog->setObjectName("ADialog");
        splitter_2->addWidget(ADialog);
        splitter_4->addWidget(splitter_2);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_3);
        label_2->setObjectName("label_2");
        splitter_3->addWidget(label_2);
        BDialog = new QLineEdit(splitter_3);
        BDialog->setObjectName("BDialog");
        splitter_3->addWidget(BDialog);
        splitter_4->addWidget(splitter_3);
        splitter_5->addWidget(splitter_4);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Format: 0.0, 0.6, 0.4...", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Szum:", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "A:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "B:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
