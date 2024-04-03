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



// void MainWindow::ReadSerialData()
// {
//     // Potentiometre
//     float speed;
//     float acc;

//     // Accelerometre
//     float speed_acc_x;
//     float speed_acc_y;
//     float speed_norm;
//     float pos_acc;

//     QByteArray data = port->readAll();
//     if (data.isEmpty())
//     {
//         qDebug() << "Empty Data";
//     }
//     else
//     {
//         QByteArray newdata = data;
//         QByteArrayList data_list = newdata.split('_');

//         if (ui->cmb_comp->currentText() == "Potentiomètre")
//         {
//             ui->lcd_acc_x->display("0");
//             ui->lcd_acc_y->display("0");

//             ui->lcd_acc_x->display("0");
//             ui->lcd_acc_y->display("0");

//             if(data_list.size() >=2 && (data_list[0].toStdString().find(POT_FOUND)!= std::string::npos
//                                           ||  data_list[0] == "PA" || data_list[0] == "P"))
//             {
//                 // Afficher l'angle
//                 ui->lcd_pos->display(data_list[1].toInt());

//                 // Afficher la courbe
//                 if(acquire==1)
//                 {
//                     qDebug() << "entered acuire = 1";
//                     yData.append(data_list[1].toInt());
//                     xData.append(timer.elapsed()/1000);
//                     iData++;
//                     graph1(ui->customPlot);
//                     if(timer.elapsed()>=tMax*1000)
//                     {
//                         qDebug() << "entered if";
//                         acquire=0;
//                         //                        graph1(ui->customPlot);
//                         timer.invalidate();
//                         xData.clear();
//                         yData.clear();
//                         qDebug() << "finished if";
//                     }
//                 }


//                 // Remplir le tableau d'angles
//                 tab_pos[cnt_pos] = data_list[1].toFloat();
//                 cnt_pos++;

//                 // Check the size of the table
//                 if((sizeof(tab_pos)/sizeof(tab_pos[0])) == 1)
//                 {
//                     //nothing to do here, just move on
//                 }
//                 else
//                 {
//                     // speed = angle actuel - angle precedent / 100 millisecondes
//                     speed = (tab_pos[cnt_pos] - tab_pos[cnt_pos-1])/100;

//                     // Afficher la vitesse
//                     ui->lcd_vitesse->display(abs(speed));

//                     // Remplir le tablea de vitesses
//                     tab_speed[cnt_speed] = speed;
//                     cnt_speed++;

//                     // Check the size of the table
//                     if((sizeof(tab_speed)/sizeof(tab_speed[0])) == 1)
//                     {
//                         //nothing to do here, just move on
//                     }
//                     else
//                     {
//                         // acc = speed actuel - speed precedent / 100 millisecondes
//                         acc = (tab_speed[cnt_speed] - tab_speed[cnt_speed-1])/100;
//                         ui->lcd_acc_x->display(acc*100);
//                     }
//                 }
//             }
//         }

//         if (ui->cmb_comp->currentText() == "Encodeur")
//         {
//             ui->lcd_vitesse->display(0);
//             ui->lcd_acc_x->display("0");
//             ui->lcd_acc_y->display("0");

//             if(data_list.size() >=2 && (data_list[0].toStdString().find(ENCOD_FOUND)!= std::string::npos
//                                           ||  data_list[0] == "EA" || data_list[0] == "E"))
//             {
//                 ui->lcd_pos->display(data_list[1].toInt());
//             }
//         }

//         if (ui->cmb_comp->currentText() == "Accéléromètre")
//         {

//             if(data_list.size() > 2 && (data_list[0].toStdString().find(ACC_FOUND)!= std::string::npos
//                                          ||  data_list[0] == "ACC" || data_list[0] == "AC" || data_list[0] == "C" || data_list[0] == "CC"))
//             {
//                 if(data_list[1].toFloat()!=0 && data_list[2].toFloat()!=0)
//                 {
//                     ui->lcd_acc_x->display(data_list[1].toFloat());
//                     ui->lcd_acc_y->display(data_list[2].toFloat());
//                 }
//                 else if(data_list[1].toFloat()==0 && data_list[2].toFloat()!=0) {
//                     ui->lcd_acc_y->display(data_list[2].toFloat());
//                 }
//                 else if(data_list[1].toFloat()==0 && data_list[2].toFloat()==0) {
//                     ui->lcd_acc_x->display(data_list[1].toFloat());
//                 }
//                 else {

//                 }

//                 // Remplir le tableau d'angles
//                 tab_acc_x[cnt_acc_x] = data_list[1].toFloat();
//                 cnt_acc_x++;
//                 tab_acc_y[cnt_acc_y] = data_list[2].toFloat();
//                 cnt_acc_y++;

//                 // Check if the size of the tables is equal to 1 item1
//                 if( (sizeof(tab_acc_x)/sizeof(tab_acc_x[0])) == 1 && (sizeof(tab_acc_x)/sizeof(tab_acc_x[0])))
//                 {
//                     //nothing to do here, just move on
//                 }
//                 else
//                 {
//                     speed_acc_x = (tab_acc_x[cnt_acc_x] - tab_acc_x[cnt_acc_x-1])*100;
//                     speed_acc_y = (tab_acc_y[cnt_acc_y] - tab_acc_y[cnt_acc_y-1])*100;

//                     // Afficher la vitesse
//                     ui->lcd_vitesse->display(abs(speed_acc_x));
//                     ui->lcd_vitesse->display(abs(speed_acc_y));

//                     // Remplir le tablea de vitesses
//                     tab_acc_speed_x[cnt_acc_speed_x] = speed_acc_x;
//                     cnt_acc_speed_x++;

//                     tab_acc_speed_y[cnt_acc_speed_y] = speed_acc_y;
//                     cnt_acc_speed_y++;

//                     // Check the size of the table
//                     if((sizeof(tab_acc_speed_x)/sizeof(tab_acc_speed_x[0])) == 1 && (sizeof(tab_acc_speed_x)/sizeof(tab_acc_speed_x[0])))
//                     {
//                         //nothing to do here, just move on
//                     }
//                     else
//                     {
//                         // Display the norm speed
//                         speed_norm = sqrt(pow(speed_acc_x,2) + pow(speed_acc_y,2));
//                         ui->lcd_vitesse->display(speed_norm);

//                         // Fill the norm speed table
//                         tab_acc_speed_norm[cnt_acc_speed_norm] = speed_norm;
//                         cnt_acc_speed_norm++;

//                         if((sizeof(tab_acc_speed_norm)/sizeof(tab_acc_speed_norm[0])) == 1 )
//                         {
//                             //nothing to do here, just move on
//                         }
//                         else
//                         {
//                             // Display the acceleration
//                             pos_acc = tab_acc_speed_norm[cnt_acc_speed_norm] - tab_acc_speed_norm[cnt_acc_speed_norm-1] * 100;
//                             ui->lcd_pos->display(abs(pos_acc)/32);
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

/**************************************************************************************/


