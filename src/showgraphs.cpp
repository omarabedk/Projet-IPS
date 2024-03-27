#include "showgraphs.h"
#include "ui_mainwindow.h"

ShowGraphs::ShowGraphs(Ui::MainWindow *ui):mainUi(ui)
{
    HighGraphTimer();
    updateHighGraph();
    PowerGraphTimer();
    updatePowerGraph();
}

void ShowGraphs::HighGraphTimer() {
    mainUi->HighTimeGraph->addGraph();
    mainUi->HighTimeGraph->plotLayout()->insertRow(0); // Insert a new row at the top for the title
    mainUi->HighTimeGraph->plotLayout()->addElement(0, 0, new QCPTextElement(mainUi->HighTimeGraph, "High values", QFont("sans", 12, QFont::Bold)));
    mainUi->HighTimeGraph->xAxis->setLabel("Time (seconds)");
    mainUi->HighTimeGraph->yAxis->setLabel("High (meters)");


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateHighGraph()));
    timer->start(1000);
}

void ShowGraphs::updateHighGraph() {
    bool ok;
    double value = mainUi->setHightxt->text().toDouble(&ok);
    if (ok) {
        QCPGraph *graph = mainUi->HighTimeGraph->graph(0);
        int dataCount = graph->dataCount();
        graph->addData(dataCount, value);

        mainUi->HighTimeGraph->yAxis->rescale(true);

        mainUi->HighTimeGraph->xAxis->setRange(dataCount - 10, dataCount);
        mainUi->HighTimeGraph->replot();
    }
}

void ShowGraphs::PowerGraphTimer() {
    mainUi->PowerTimeGraph->addGraph();
    mainUi->PowerTimeGraph->plotLayout()->insertRow(0); // Insert a new row at the top for the title
    mainUi->PowerTimeGraph->plotLayout()->addElement(0, 0, new QCPTextElement(mainUi->PowerTimeGraph, "Power values", QFont("sans", 12, QFont::Bold)));
    mainUi->PowerTimeGraph->xAxis->setLabel("Time (seconds)");
    mainUi->PowerTimeGraph->yAxis->setLabel("Power (watt)");
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePowerGraph()));
    timer->start(1000);
}

void ShowGraphs::updatePowerGraph() {
    bool ok;
    double value = mainUi->setGaintxt->text().toDouble(&ok);
    if (ok) {
        QCPGraph *graph = mainUi->PowerTimeGraph->graph(0);
        int dataCount = graph->dataCount();
        graph->addData(dataCount, value);

        mainUi->PowerTimeGraph->yAxis->rescale(true);

        mainUi->PowerTimeGraph->xAxis->setRange(dataCount - 10, dataCount);
        mainUi->PowerTimeGraph->replot();
    }
}
