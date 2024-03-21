#include "showgraphs.h"
#include "ui_mainwindow.h"

ShowGraphs::ShowGraphs(Ui::MainWindow *ui)//:mainUi(ui)
{
}

void ShowGraphs::RealTimePlotter(Ui::MainWindow *ui) {
    // Set up the timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGraph()));
    timer->start(1000); // 1000ms -> 1 second
}

void ShowGraphs::updateGraph(Ui::MainWindow *ui) {
    bool ok;
    double value = ui->setHightxt->text().toDouble(&ok);
    if (ok) {
        // Here you would update the graph with the new value
        // This is just a placeholder for the actual graph update logic
        ui->HighTimeGraph->graph(0)->addData(ui->HighTimeGraph->graph(0)->dataCount(), value);
        ui->HighTimeGraph->replot();
    }
}
