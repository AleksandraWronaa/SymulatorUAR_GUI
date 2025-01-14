/********************************************************************************
** Form generated from reading UI file 'symulator.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMULATOR_H
#define UI_SYMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Symulator
{
public:
    QWidget *centralwidget;
    QPushButton *button_zapisz;
    QPushButton *button_wczytaj;
    QGroupBox *groupBox_PID;
    QDoubleSpinBox *spinbox_D;
    QDoubleSpinBox *spinbox_I;
    QLabel *label_D;
    QLabel *label_P;
    QLabel *label_I;
    QDoubleSpinBox *spinbox_P;
    QGroupBox *groupBox_ARX;
    QDoubleSpinBox *spinbox_B;
    QLabel *label_A;
    QLabel *label_k;
    QDoubleSpinBox *spinbox_A;
    QLabel *label_B;
    QDoubleSpinBox *spinbox_k;
    QGroupBox *groupBox_WartoscZadana;
    QListWidget *list_WartoscZadana;
    QLabel *label_maksimumY;
    QDoubleSpinBox *spinbox_maksimumY;
    QLabel *label_okres;
    QSpinBox *spinbox_okres;
    QGroupBox *groupBox_UstawieniaFiltra;
    QDoubleSpinBox *spinbox_maksimum;
    QLabel *label_minimum;
    QDoubleSpinBox *spinbox_minimum;
    QLabel *label_maksimum;
    QPushButton *button_start;
    QPushButton *button_reset;
    QPushButton *button_stop;
    QLabel *label_interval;
    QDoubleSpinBox *spinbox_interval;
    QLabel *label_ms;
    QCustomPlot *wykres;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Symulator)
    {
        if (Symulator->objectName().isEmpty())
            Symulator->setObjectName("Symulator");
        Symulator->resize(1147, 641);
        centralwidget = new QWidget(Symulator);
        centralwidget->setObjectName("centralwidget");
        button_zapisz = new QPushButton(centralwidget);
        button_zapisz->setObjectName("button_zapisz");
        button_zapisz->setGeometry(QRect(982, 120, 121, 41));
        QFont font;
        font.setBold(true);
        button_zapisz->setFont(font);
        button_wczytaj = new QPushButton(centralwidget);
        button_wczytaj->setObjectName("button_wczytaj");
        button_wczytaj->setGeometry(QRect(980, 180, 121, 41));
        button_wczytaj->setFont(font);
        groupBox_PID = new QGroupBox(centralwidget);
        groupBox_PID->setObjectName("groupBox_PID");
        groupBox_PID->setGeometry(QRect(20, 410, 201, 171));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        groupBox_PID->setFont(font1);
        groupBox_PID->setAlignment(Qt::AlignCenter);
        spinbox_D = new QDoubleSpinBox(groupBox_PID);
        spinbox_D->setObjectName("spinbox_D");
        spinbox_D->setGeometry(QRect(80, 130, 81, 29));
        spinbox_D->setMinimum(-99.989999999999995);
        spinbox_I = new QDoubleSpinBox(groupBox_PID);
        spinbox_I->setObjectName("spinbox_I");
        spinbox_I->setGeometry(QRect(80, 90, 81, 29));
        spinbox_I->setMinimum(-99.989999999999995);
        label_D = new QLabel(groupBox_PID);
        label_D->setObjectName("label_D");
        label_D->setGeometry(QRect(40, 130, 31, 20));
        label_D->setFont(font1);
        label_D->setTextFormat(Qt::AutoText);
        label_D->setAlignment(Qt::AlignCenter);
        label_P = new QLabel(groupBox_PID);
        label_P->setObjectName("label_P");
        label_P->setGeometry(QRect(40, 50, 31, 20));
        label_P->setFont(font1);
        label_P->setTextFormat(Qt::AutoText);
        label_P->setAlignment(Qt::AlignCenter);
        label_I = new QLabel(groupBox_PID);
        label_I->setObjectName("label_I");
        label_I->setGeometry(QRect(40, 90, 31, 20));
        label_I->setFont(font1);
        label_I->setTextFormat(Qt::AutoText);
        label_I->setAlignment(Qt::AlignCenter);
        spinbox_P = new QDoubleSpinBox(groupBox_PID);
        spinbox_P->setObjectName("spinbox_P");
        spinbox_P->setGeometry(QRect(80, 50, 81, 29));
        spinbox_P->setMinimum(-99.989999999999995);
        groupBox_ARX = new QGroupBox(centralwidget);
        groupBox_ARX->setObjectName("groupBox_ARX");
        groupBox_ARX->setGeometry(QRect(250, 410, 191, 171));
        groupBox_ARX->setFont(font1);
        groupBox_ARX->setAlignment(Qt::AlignCenter);
        spinbox_B = new QDoubleSpinBox(groupBox_ARX);
        spinbox_B->setObjectName("spinbox_B");
        spinbox_B->setGeometry(QRect(80, 130, 81, 29));
        spinbox_B->setMinimum(-99.989999999999995);
        label_A = new QLabel(groupBox_ARX);
        label_A->setObjectName("label_A");
        label_A->setGeometry(QRect(40, 90, 31, 20));
        label_A->setFont(font1);
        label_A->setTextFormat(Qt::AutoText);
        label_A->setAlignment(Qt::AlignCenter);
        label_k = new QLabel(groupBox_ARX);
        label_k->setObjectName("label_k");
        label_k->setGeometry(QRect(40, 40, 31, 20));
        label_k->setFont(font1);
        label_k->setTextFormat(Qt::AutoText);
        label_k->setAlignment(Qt::AlignCenter);
        spinbox_A = new QDoubleSpinBox(groupBox_ARX);
        spinbox_A->setObjectName("spinbox_A");
        spinbox_A->setGeometry(QRect(80, 90, 81, 29));
        spinbox_A->setMinimum(-99.989999999999995);
        label_B = new QLabel(groupBox_ARX);
        label_B->setObjectName("label_B");
        label_B->setGeometry(QRect(40, 130, 31, 20));
        label_B->setFont(font1);
        label_B->setTextFormat(Qt::AutoText);
        label_B->setAlignment(Qt::AlignCenter);
        spinbox_k = new QDoubleSpinBox(groupBox_ARX);
        spinbox_k->setObjectName("spinbox_k");
        spinbox_k->setGeometry(QRect(80, 40, 81, 29));
        groupBox_WartoscZadana = new QGroupBox(centralwidget);
        groupBox_WartoscZadana->setObjectName("groupBox_WartoscZadana");
        groupBox_WartoscZadana->setGeometry(QRect(480, 430, 381, 151));
        groupBox_WartoscZadana->setFont(font1);
        groupBox_WartoscZadana->setAlignment(Qt::AlignCenter);
        list_WartoscZadana = new QListWidget(groupBox_WartoscZadana);
        list_WartoscZadana->setObjectName("list_WartoscZadana");
        list_WartoscZadana->setGeometry(QRect(20, 50, 171, 81));
        list_WartoscZadana->setLayoutDirection(Qt::LeftToRight);
        label_maksimumY = new QLabel(groupBox_WartoscZadana);
        label_maksimumY->setObjectName("label_maksimumY");
        label_maksimumY->setGeometry(QRect(210, 60, 71, 20));
        label_maksimumY->setFont(font1);
        label_maksimumY->setTextFormat(Qt::AutoText);
        label_maksimumY->setAlignment(Qt::AlignCenter);
        spinbox_maksimumY = new QDoubleSpinBox(groupBox_WartoscZadana);
        spinbox_maksimumY->setObjectName("spinbox_maksimumY");
        spinbox_maksimumY->setGeometry(QRect(290, 50, 81, 29));
        label_okres = new QLabel(groupBox_WartoscZadana);
        label_okres->setObjectName("label_okres");
        label_okres->setGeometry(QRect(210, 100, 71, 20));
        label_okres->setFont(font1);
        label_okres->setTextFormat(Qt::AutoText);
        label_okres->setAlignment(Qt::AlignCenter);
        spinbox_okres = new QSpinBox(groupBox_WartoscZadana);
        spinbox_okres->setObjectName("spinbox_okres");
        spinbox_okres->setGeometry(QRect(290, 100, 81, 29));
        groupBox_UstawieniaFiltra = new QGroupBox(centralwidget);
        groupBox_UstawieniaFiltra->setObjectName("groupBox_UstawieniaFiltra");
        groupBox_UstawieniaFiltra->setGeometry(QRect(880, 430, 221, 151));
        groupBox_UstawieniaFiltra->setFont(font1);
        groupBox_UstawieniaFiltra->setAlignment(Qt::AlignCenter);
        spinbox_maksimum = new QDoubleSpinBox(groupBox_UstawieniaFiltra);
        spinbox_maksimum->setObjectName("spinbox_maksimum");
        spinbox_maksimum->setGeometry(QRect(130, 100, 81, 29));
        spinbox_maksimum->setMinimum(-99.989999999999995);
        label_minimum = new QLabel(groupBox_UstawieniaFiltra);
        label_minimum->setObjectName("label_minimum");
        label_minimum->setGeometry(QRect(10, 50, 101, 20));
        label_minimum->setFont(font1);
        label_minimum->setTextFormat(Qt::AutoText);
        label_minimum->setAlignment(Qt::AlignCenter);
        spinbox_minimum = new QDoubleSpinBox(groupBox_UstawieniaFiltra);
        spinbox_minimum->setObjectName("spinbox_minimum");
        spinbox_minimum->setGeometry(QRect(130, 50, 81, 29));
        spinbox_minimum->setMinimum(-99.989999999999995);
        label_maksimum = new QLabel(groupBox_UstawieniaFiltra);
        label_maksimum->setObjectName("label_maksimum");
        label_maksimum->setGeometry(QRect(10, 100, 111, 20));
        label_maksimum->setFont(font1);
        label_maksimum->setTextFormat(Qt::AutoText);
        label_maksimum->setAlignment(Qt::AlignCenter);
        button_start = new QPushButton(centralwidget);
        button_start->setObjectName("button_start");
        button_start->setGeometry(QRect(510, 340, 121, 41));
        button_start->setFont(font);
        button_reset = new QPushButton(centralwidget);
        button_reset->setObjectName("button_reset");
        button_reset->setGeometry(QRect(660, 340, 121, 41));
        button_reset->setFont(font);
        button_stop = new QPushButton(centralwidget);
        button_stop->setObjectName("button_stop");
        button_stop->setGeometry(QRect(360, 340, 121, 41));
        button_stop->setFont(font);
        label_interval = new QLabel(centralwidget);
        label_interval->setObjectName("label_interval");
        label_interval->setGeometry(QRect(850, 350, 101, 20));
        label_interval->setFont(font1);
        label_interval->setTextFormat(Qt::AutoText);
        label_interval->setAlignment(Qt::AlignCenter);
        spinbox_interval = new QDoubleSpinBox(centralwidget);
        spinbox_interval->setObjectName("spinbox_interval");
        spinbox_interval->setGeometry(QRect(950, 350, 81, 29));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        spinbox_interval->setFont(font2);
        spinbox_interval->setDecimals(0);
        spinbox_interval->setMinimum(10.000000000000000);
        spinbox_interval->setMaximum(10000.000000000000000);
        label_ms = new QLabel(centralwidget);
        label_ms->setObjectName("label_ms");
        label_ms->setGeometry(QRect(870, 370, 49, 16));
        wykres = new QCustomPlot(centralwidget);
        wykres->setObjectName("wykres");
        wykres->setGeometry(QRect(30, 20, 931, 311));
        Symulator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Symulator);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1147, 21));
        Symulator->setMenuBar(menubar);
        statusbar = new QStatusBar(Symulator);
        statusbar->setObjectName("statusbar");
        Symulator->setStatusBar(statusbar);

        retranslateUi(Symulator);

        QMetaObject::connectSlotsByName(Symulator);
    } // setupUi

    void retranslateUi(QMainWindow *Symulator)
    {
        Symulator->setWindowTitle(QCoreApplication::translate("Symulator", "Symulator", nullptr));
        button_zapisz->setText(QCoreApplication::translate("Symulator", "Zapisz do pliku", nullptr));
        button_wczytaj->setText(QCoreApplication::translate("Symulator", "Wczytaj z pliku", nullptr));
        groupBox_PID->setTitle(QCoreApplication::translate("Symulator", "PID", nullptr));
        label_D->setText(QCoreApplication::translate("Symulator", "D", nullptr));
        label_P->setText(QCoreApplication::translate("Symulator", "P", nullptr));
        label_I->setText(QCoreApplication::translate("Symulator", "I", nullptr));
        groupBox_ARX->setTitle(QCoreApplication::translate("Symulator", "ARX", nullptr));
        label_A->setText(QCoreApplication::translate("Symulator", "A", nullptr));
        label_k->setText(QCoreApplication::translate("Symulator", "k", nullptr));
        label_B->setText(QCoreApplication::translate("Symulator", "B", nullptr));
        groupBox_WartoscZadana->setTitle(QCoreApplication::translate("Symulator", "Warto\305\233\304\207 Zadana", nullptr));
        label_maksimumY->setText(QCoreApplication::translate("Symulator", "Max Y", nullptr));
        label_okres->setText(QCoreApplication::translate("Symulator", "Okres", nullptr));
        groupBox_UstawieniaFiltra->setTitle(QCoreApplication::translate("Symulator", "Ustawienia filtra", nullptr));
        label_minimum->setText(QCoreApplication::translate("Symulator", "Minimum", nullptr));
        label_maksimum->setText(QCoreApplication::translate("Symulator", "Maksimum", nullptr));
        button_start->setText(QCoreApplication::translate("Symulator", "Start", nullptr));
        button_reset->setText(QCoreApplication::translate("Symulator", "Reset", nullptr));
        button_stop->setText(QCoreApplication::translate("Symulator", "Stop", nullptr));
        label_interval->setText(QCoreApplication::translate("Symulator", "Interwa\305\202", nullptr));
        label_ms->setText(QCoreApplication::translate("Symulator", "(w ms)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Symulator: public Ui_Symulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMULATOR_H
