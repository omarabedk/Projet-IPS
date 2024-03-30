#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "showgraphs.h"
#include <QFile>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

