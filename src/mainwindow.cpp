#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "showgraphs.h"

ShowGraphs *showGraphs;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showGraphs = new ShowGraphs(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

