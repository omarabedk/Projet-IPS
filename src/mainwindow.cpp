#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include "showgraphs.h"

ShowGraphs *showGraphs;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showGraphs = new ShowGraphs(ui);

    QString styleSheet = "QMainWindow { background-color: #3498db; }"
                         "QWidget#centralwidget { background-color: #ecf0f1; }"
                         "QLabel { font-size: 15px; color: #2c3e50; }"
                         "QPushButton { background-color: #2ecc71; color: white; border: none; border-radius: 4px; padding: 10px 20px; font-size: 16px; }"
                         "QPushButton:hover { background-color: #27ae60; }";
    this->setStyleSheet(styleSheet);
    port = new QSerialPort(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************************************************/

void MainWindow::on_ConnectBttn_clicked()
{
    QString Sport = ui->portNumberSpin->text();
    QString Sbaude = ui->baudeRatespin->text();
    com_value = Sport.toInt();
    baud_value = Sbaude.toInt();

    if (port->isOpen()) port->close();
    openPort();
}


/**************************************************************************************/

void MainWindow::openPort()
{
    port->setPortName("COM"+QString::number(com_value));
    port->setBaudRate(baud_value);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);

    if (port->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, "Connection Established", "The connection on port : COM" + ui->portNumberSpin->text() + " is established!" , QMessageBox::Ok);
        // Connection Established
        port->write("Connection Established\n");
        ui->ErrorLbl->setText("Connected");
        ui->ErrorLbl->setStyleSheet("QLabel { color : green; }");
        qDebug() << "Serial port is open...";

        // To clear the serial port and delete the old data before read it again
        port->clear();

        // To Receive Data in a continuous way
        connect(port,SIGNAL(readyRead()),this,SLOT(ReadSerialData()));
    }
    else
    {
        // Connection Problem
        qDebug() << "OPEN ERROR: " << port->errorString();
        QMessageBox::critical(this, "Wrong COM Port!", port->errorString());
        ui->ErrorLbl->setText("Disconnected");
        ui->ErrorLbl->setStyleSheet("QLabel { color : red; }");
        port->close();
        qDebug() << "...serial port is closed!";
    }
}


/**************************************************************************************/



void MainWindow::ReadSerialData()
{
    QByteArray data = port->readAll();
    if (data.isEmpty())
    {
        qDebug() << "Empty Data";
    }
    else
    {
        if(data[0]=='H'){
        QString strData = QString::fromUtf8(data.mid(1));
        ui->highValueLbl->setText(strData);
        }
        else{
            qDebug()<<"Data type not specified";
        }
    }
}

/**************************************************************************************/


void MainWindow::on_DisconnectBttn_clicked()
{
    port->close();
    ui->ErrorLbl->setText("Disconnected");
    ui->ErrorLbl->setStyleSheet("QLabel { color : red; }");
}

