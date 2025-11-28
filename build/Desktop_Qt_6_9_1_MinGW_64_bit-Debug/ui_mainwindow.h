/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *plot_1;
    QCustomPlot *plot_2;
    QCustomPlot *plot_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *btplot;
    QPushButton *btsearch;
    QPushButton *compute;
    QFrame *line;
    QFrame *line_2;
    QLineEdit *time_search;
    QLineEdit *xcoord;
    QLineEdit *ycoord;
    QLineEdit *baterylvl;
    QLineEdit *txt_tmin;
    QLineEdit *txt_tmax;
    QLineEdit *integral;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1289, 769);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        plot_1 = new QCustomPlot(centralwidget);
        plot_1->setObjectName("plot_1");
        plot_1->setGeometry(QRect(20, 20, 1251, 171));
        plot_2 = new QCustomPlot(centralwidget);
        plot_2->setObjectName("plot_2");
        plot_2->setGeometry(QRect(20, 210, 1251, 171));
        plot_3 = new QCustomPlot(centralwidget);
        plot_3->setObjectName("plot_3");
        plot_3->setGeometry(QRect(20, 390, 1251, 171));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 600, 41, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 580, 61, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(440, 620, 61, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 670, 21, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(740, 580, 41, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(740, 620, 41, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(1090, 590, 51, 20));
        btplot = new QPushButton(centralwidget);
        btplot->setObjectName("btplot");
        btplot->setGeometry(QRect(50, 650, 90, 29));
        btsearch = new QPushButton(centralwidget);
        btsearch->setObjectName("btsearch");
        btsearch->setGeometry(QRect(240, 660, 161, 29));
        compute = new QPushButton(centralwidget);
        compute->setObjectName("compute");
        compute->setGeometry(QRect(740, 660, 471, 29));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(200, 570, 20, 151));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(690, 570, 20, 151));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        time_search = new QLineEdit(centralwidget);
        time_search->setObjectName("time_search");
        time_search->setGeometry(QRect(270, 600, 113, 28));
        xcoord = new QLineEdit(centralwidget);
        xcoord->setObjectName("xcoord");
        xcoord->setGeometry(QRect(510, 580, 113, 28));
        ycoord = new QLineEdit(centralwidget);
        ycoord->setObjectName("ycoord");
        ycoord->setGeometry(QRect(510, 620, 113, 28));
        baterylvl = new QLineEdit(centralwidget);
        baterylvl->setObjectName("baterylvl");
        baterylvl->setGeometry(QRect(510, 660, 113, 28));
        txt_tmin = new QLineEdit(centralwidget);
        txt_tmin->setObjectName("txt_tmin");
        txt_tmin->setGeometry(QRect(790, 580, 191, 28));
        txt_tmax = new QLineEdit(centralwidget);
        txt_tmax->setObjectName("txt_tmax");
        txt_tmax->setGeometry(QRect(790, 620, 191, 28));
        integral = new QLineEdit(centralwidget);
        integral->setObjectName("integral");
        integral->setGeometry(QRect(1030, 620, 171, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1289, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X Coord", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y Coord", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Bat", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "t min", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "t max", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Energy", nullptr));
        btplot->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        btsearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        compute->setText(QCoreApplication::translate("MainWindow", "Compute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
