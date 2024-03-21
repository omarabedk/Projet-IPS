#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RealTimePlotter();
    updateGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RealTimePlotter() {
    ui->HighTimeGraph->addGraph();
    // Set up the timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGraph()));
    timer->start(1000); // 1000ms -> 1 second
}

void MainWindow::updateGraph() {
    bool ok;
    double value = ui->setHightxt->text().toDouble(&ok);
    if (ok) {
        // Add the new data
        QCPGraph *graph = ui->HighTimeGraph->graph(0);
        int dataCount = graph->dataCount();
        graph->addData(dataCount, value);

        // Rescale the value (y) axis to fit the new data
        ui->HighTimeGraph->yAxis->rescale(true);

        // If you want to expand the time (x) axis dynamically as well, use this:
        ui->HighTimeGraph->xAxis->setRange(dataCount - 10, dataCount); // Show last 10 data points

        // Redraw the graph
        ui->HighTimeGraph->replot();
    }
}

