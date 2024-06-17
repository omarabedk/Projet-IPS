#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
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
                         "QLabel { font-size: 15px; color: #2c3e50;text-align: center;}"
                         "QPushButton { background-color: #2ecc71; color: white; border: none; border-radius: 4px;font-size: 14px; }"
                         "QPushButton:hover { background-color: #27ae60; }";
    this->setStyleSheet(styleSheet);
    port = new QSerialPort(this);

    // Timer setup
    timer = new QTimer(this);  // Initialize timer
    connect(timer, &QTimer::timeout, this, &MainWindow::ReadSerialData);  // Connect timer signal to ReadSerialData slot
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************************************************/
/*                              CONNECTION                                            */
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
/*                              OPEN PORT                                             */
/**************************************************************************************/

void MainWindow::openPort()
{
    port->setPortName("COM" + QString::number(com_value));
    port->setBaudRate(baud_value);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);

    if (port->open(QIODevice::ReadWrite))
    {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Connection Established");
        msgBox.setText("The connection on port : COM" + ui->portNumberSpin->text() + " is established!");

        QPushButton *okButton = msgBox.addButton(QMessageBox::Ok);
        QSize buttonSize(80, 30);
        okButton->setFixedSize(buttonSize);

        msgBox.exec();

        port->write("Connection Established\n");
        ui->ErrorLbl->setText("Connected");
        ui->ErrorLbl->setStyleSheet("QLabel { color : green; }");
        qDebug() << "Serial port is open...";

        port->clear();

        // Start the timer with 1-second interval
        timer->start(1000);
    }
    else
    {
        qDebug() << "OPEN ERROR: " << port->errorString();
        QMessageBox::critical(this, "Wrong COM Port!", port->errorString());
        ui->ErrorLbl->setText("Disconnected");
        ui->ErrorLbl->setStyleSheet("QLabel { color : red; }");
        port->close();
        qDebug() << "...serial port is closed!";
    }
}



/**************************************************************************************/
/*                              READ DATA FROM STM32                                  */
/**************************************************************************************/

void MainWindow::ReadSerialData() {
    serialBuffer.append(port->readAll());

    int endIndex;
    while ((endIndex = serialBuffer.indexOf(';')) != -1) {
        QByteArray message = serialBuffer.left(endIndex);
        serialBuffer.remove(0, endIndex + 1);

        if (message.startsWith('H')) {
            QString HighData = QString::fromUtf8(message.mid(1));
            ui->highValueLbl->setText(HighData);
        } else if (message.startsWith('P')) {
            QString PowerData = QString::fromUtf8(message.mid(1));
            ui->PowerValueLbl->setText(PowerData);
        } else {
            qDebug() << "Data type not specified";
        }
    }
}


/**************************************************************************************/
/*                              DISCONNECTION                                         */
/**************************************************************************************/

void MainWindow::on_DisconnectBttn_clicked()
{
    port->close();
    ui->ErrorLbl->setText("Disconnected");
    ui->ErrorLbl->setStyleSheet("QLabel { color : red; }");
    ui->highValueLbl->setText("");
    ui->PowerValueLbl->setText("");
    timer->stop();  // Stop the timer when disconnected
}

/**************************************************************************************/
/*                              SEND HIGH VALUE TO STM32                              */
/**************************************************************************************/

void MainWindow::on_sendHighBttn_clicked()
{
    QString highData = ui->setHightxt->text();
    if (!highData.isEmpty())
    {
        for (int i=0;i<100;i++){
            QByteArray dataToSend = 'H' + highData.toUtf8();
            port->write(dataToSend);
            qDebug() << "Sent High Data:" << dataToSend;
        }
        int HighDataInt = highData.toInt();
        showGraphs->drawConstantLine(HighDataInt);
    }
    else
    {
        qDebug() << "High Data text box is empty.";
    }
}

/**************************************************************************************/
/*                              SEND GAIN VALUE TO STM32                              */
/**************************************************************************************/

void MainWindow::on_sendGainBttn_clicked()
{

    QString gainData = ui->setGaintxt->text();
    if (!gainData.isEmpty())
    {
        for (int i=0;i<100;i++){
            QByteArray dataToSend = 'G' + gainData.toUtf8();
            port->write(dataToSend);
            qDebug() << "Sent Gain Data:" << dataToSend;
        }
    }
    else
    {
        qDebug() << "Gain Data text box is empty.";
    }

}
