#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void openPort();

private slots:
    void on_ConnectBttn_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *port;
    int baud_value;
    int com_value;
};
#endif // MAINWINDOW_H
