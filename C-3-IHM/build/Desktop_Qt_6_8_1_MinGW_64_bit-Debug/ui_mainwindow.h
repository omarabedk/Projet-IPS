/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *HighTimeGraph;
    QSpacerItem *horizontalSpacer_2;
    QCustomPlot *PowerHighGraph;
    QFrame *line;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *highValueLbl;
    QLabel *PowerValueLbl;
    QCustomPlot *PowerTimeGraph;
    QGroupBox *groupBox_3;
    QSpinBox *setHightxt;
    QLabel *label_12;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *sendHighBttn;
    QPushButton *sendGainBttn;
    QDoubleSpinBox *setGaintxt;
    QGroupBox *groupBox;
    QSpinBox *portNumberSpin;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *ConnectBttn;
    QLabel *ErrorLbl;
    QLabel *label_11;
    QSpinBox *baudeRatespin;
    QPushButton *DisconnectBttn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1129, 949);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        HighTimeGraph = new QCustomPlot(centralwidget);
        HighTimeGraph->setObjectName("HighTimeGraph");
        HighTimeGraph->setMinimumSize(QSize(0, 250));
        HighTimeGraph->setBaseSize(QSize(0, 0));
        HighTimeGraph->setStyleSheet(QString::fromUtf8("#HighTimeGraph {\n"
"            background-color: #f0f0f0;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 5px;\n"
"        }"));

        gridLayout->addWidget(HighTimeGraph, 18, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 5, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 17, 4, 1, 2);

        PowerHighGraph = new QCustomPlot(centralwidget);
        PowerHighGraph->setObjectName("PowerHighGraph");
        PowerHighGraph->setMinimumSize(QSize(0, 300));
        PowerHighGraph->setBaseSize(QSize(300, 300));
        PowerHighGraph->setStyleSheet(QString::fromUtf8(" #PowerHighGraph {\n"
"            background-color: #f0f0f0; /* Set background color */\n"
"            border: 1px solid #ccc; /* Add a border */\n"
"            border-radius: 5px; /* Round the corners */\n"
"        }"));

        gridLayout->addWidget(PowerHighGraph, 19, 4, 1, 2);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 16, 4, 1, 2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 50));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("font-size: 20px;\n"
"text-align: center;\n"
"background-color: #00B8EE;"));

        gridLayout->addWidget(label, 1, 4, 1, 2);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(500, 100));
        QFont font;
        font.setBold(true);
        font.setUnderline(false);
        groupBox_2->setFont(font);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 30, 100, 20));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 70, 100, 20));
        label_7->setMaximumSize(QSize(100, 16777215));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(270, 70, 50, 20));
        label_9->setMaximumSize(QSize(50, 16777215));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(270, 30, 51, 21));
        highValueLbl = new QLabel(groupBox_2);
        highValueLbl->setObjectName("highValueLbl");
        highValueLbl->setGeometry(QRect(120, 30, 121, 21));
        highValueLbl->setMaximumSize(QSize(200, 16777215));
        PowerValueLbl = new QLabel(groupBox_2);
        PowerValueLbl->setObjectName("PowerValueLbl");
        PowerValueLbl->setGeometry(QRect(110, 70, 131, 21));

        gridLayout->addWidget(groupBox_2, 9, 5, 1, 1);

        PowerTimeGraph = new QCustomPlot(centralwidget);
        PowerTimeGraph->setObjectName("PowerTimeGraph");
        PowerTimeGraph->setStyleSheet(QString::fromUtf8("#PowerTimeGraph {\n"
"            background-color: #f0f0f0; /* Set background color */\n"
"            border: 1px solid #ccc; /* Add a border */\n"
"            border-radius: 5px; /* Round the corners */\n"
"        }"));

        gridLayout->addWidget(PowerTimeGraph, 18, 5, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setMinimumSize(QSize(400, 115));
        QFont font1;
        font1.setBold(true);
        groupBox_3->setFont(font1);
        setHightxt = new QSpinBox(groupBox_3);
        setHightxt->setObjectName("setHightxt");
        setHightxt->setGeometry(QRect(90, 40, 171, 29));
        setHightxt->setMaximum(200);
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(270, 40, 31, 20));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 40, 61, 20));
        label_5->setMaximumSize(QSize(100, 16777215));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 80, 61, 29));
        label_6->setMaximumSize(QSize(100, 16777215));
        sendHighBttn = new QPushButton(groupBox_3);
        sendHighBttn->setObjectName("sendHighBttn");
        sendHighBttn->setGeometry(QRect(310, 40, 131, 31));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        sendHighBttn->setFont(font2);
        sendGainBttn = new QPushButton(groupBox_3);
        sendGainBttn->setObjectName("sendGainBttn");
        sendGainBttn->setGeometry(QRect(310, 80, 131, 29));
        sendGainBttn->setFont(font2);
        setGaintxt = new QDoubleSpinBox(groupBox_3);
        setGaintxt->setObjectName("setGaintxt");
        setGaintxt->setGeometry(QRect(90, 80, 171, 29));
        setGaintxt->setMaximum(10.000000000000000);
        setGaintxt->setSingleStep(0.010000000000000);

        gridLayout->addWidget(groupBox_3, 8, 5, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(400, 100));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setFont(font1);
        portNumberSpin = new QSpinBox(groupBox);
        portNumberSpin->setObjectName("portNumberSpin");
        portNumberSpin->setGeometry(QRect(190, 50, 91, 29));
        portNumberSpin->setMaximumSize(QSize(200, 16777215));
        portNumberSpin->setMaximum(200000);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 50, 100, 21));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 90, 100, 20));
        label_3->setMaximumSize(QSize(100, 16777215));
        ConnectBttn = new QPushButton(groupBox);
        ConnectBttn->setObjectName("ConnectBttn");
        ConnectBttn->setGeometry(QRect(40, 170, 141, 41));
        ConnectBttn->setMaximumSize(QSize(20000, 16777215));
        ConnectBttn->setStyleSheet(QString::fromUtf8(""));
        ErrorLbl = new QLabel(groupBox);
        ErrorLbl->setObjectName("ErrorLbl");
        ErrorLbl->setGeometry(QRect(30, 130, 471, 31));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(140, 50, 63, 20));
        baudeRatespin = new QSpinBox(groupBox);
        baudeRatespin->setObjectName("baudeRatespin");
        baudeRatespin->setGeometry(QRect(140, 90, 141, 29));
        baudeRatespin->setMaximum(999999);
        DisconnectBttn = new QPushButton(groupBox);
        DisconnectBttn->setObjectName("DisconnectBttn");
        DisconnectBttn->setGeometry(QRect(280, 168, 141, 41));
        DisconnectBttn->setFont(font1);
        DisconnectBttn->setStyleSheet(QString::fromUtf8("background-color: red; border-radius: 8px;\n"
""));

        gridLayout->addWidget(groupBox, 8, 4, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1129, 25));
        menubar->setStyleSheet(QString::fromUtf8(""));
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
        label->setText(QCoreApplication::translate("MainWindow", "                                                                                                         AMF IHM", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Rx Values", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "High value", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        highValueLbl->setText(QString());
        PowerValueLbl->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Tx Values", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "mm", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Set high", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Set Gain", nullptr));
        sendHighBttn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        sendGainBttn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Baude Rate", nullptr));
        ConnectBttn->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        ErrorLbl->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "COM", nullptr));
        DisconnectBttn->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
