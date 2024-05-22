#include "showgraphs.h"

ShowGraphs::ShowGraphs(Ui::MainWindow *ui):mainUi(ui)
{
    HighGraphTimer();
    PowerGraphTimer();
    PowerHighGraphTimer();
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
    double value = mainUi->highValueLbl->text().toDouble(&ok);
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
    double value = mainUi->PowerValueLbl->text().toDouble(&ok);
    if (ok) {
        QCPGraph *graph = mainUi->PowerTimeGraph->graph(0);
        int dataCount = graph->dataCount();
        graph->addData(dataCount, value);

        mainUi->PowerTimeGraph->yAxis->rescale(true);

        mainUi->PowerTimeGraph->xAxis->setRange(dataCount - 10, dataCount);
        mainUi->PowerTimeGraph->replot();
    }
}

void ShowGraphs::PowerHighGraphTimer() {
    // Add title for the graph
    mainUi->PowerHighGraph->plotLayout()->insertRow(0); // Insert a new row at the top for the title
    mainUi->PowerHighGraph->plotLayout()->addElement(0, 0, new QCPTextElement(mainUi->PowerHighGraph, "Power/High Graph", QFont("sans", 12, QFont::Bold)));

    // Add the first graph for power
    mainUi->PowerHighGraph->addGraph(mainUi->PowerHighGraph->xAxis, mainUi->PowerHighGraph->yAxis);
    mainUi->PowerHighGraph->graph(0)->setName("Power (watt)");
    mainUi->PowerHighGraph->graph(0)->setPen(QPen(Qt::blue)); // Set color for power graph

    // Add the second graph for high
    mainUi->PowerHighGraph->addGraph(mainUi->PowerHighGraph->xAxis, mainUi->PowerHighGraph->yAxis2);
    mainUi->PowerHighGraph->graph(1)->setName("High (meters)");
    mainUi->PowerHighGraph->graph(1)->setPen(QPen(Qt::red)); // Set color for high graph

    // Set up the legend
    mainUi->PowerHighGraph->legend->setVisible(true);
    mainUi->PowerHighGraph->legend->setBrush(QBrush(QColor(255,255,255,200))); // semi-transparent white background
    mainUi->PowerHighGraph->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight | Qt::AlignTop); // Align legend outside top-right

    // Set up labels and ranges
    mainUi->PowerHighGraph->xAxis->setLabel("Time (seconds)");
    mainUi->PowerHighGraph->yAxis->setLabel("Power (watt)");
    mainUi->PowerHighGraph->yAxis2->setLabel("High (meters)");

    // Make the second y-axis visible
    mainUi->PowerHighGraph->yAxis2->setVisible(true);

    // Connect timer to update function
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePowerHighGraph()));
    timer->start(1000);
}



void ShowGraphs::updatePowerHighGraph() {
    // Update power value
    bool powerOk;
    double powerValue = mainUi->PowerValueLbl->text().toDouble(&powerOk);
    if (powerOk) {
        QCPGraph *powerGraph = mainUi->PowerHighGraph->graph(0);
        int powerDataCount = powerGraph->dataCount();
        powerGraph->addData(powerDataCount, powerValue);
        mainUi->PowerHighGraph->yAxis->rescale(true);
    }

    // Update high value
    bool highOk;
    double highValue = mainUi->highValueLbl->text().toDouble(&highOk);
    if (highOk) {
        QCPGraph *highGraph = mainUi->PowerHighGraph->graph(1); // Use graph index 1 for high
        int highDataCount = highGraph->dataCount();
        highGraph->addData(highDataCount, highValue);
        mainUi->PowerHighGraph->yAxis2->rescale(true);
    }

    // Adjust x-axis range
    int dataCount = std::max(mainUi->PowerHighGraph->graph(0)->dataCount(), mainUi->PowerHighGraph->graph(1)->dataCount());
    mainUi->PowerHighGraph->xAxis->setRange(dataCount - 10, dataCount);

    // Replot the graph
    mainUi->PowerHighGraph->replot();
}


