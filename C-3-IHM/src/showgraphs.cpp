#include "showgraphs.h"
#include "qcustomplot.h"
#include <QDebug>

ShowGraphs::ShowGraphs(Ui::MainWindow *ui): mainUi(ui), threshold() // Initialize threshold
{
    HighGraphTimer();
    PowerGraphTimer();
    PowerHighGraphTimer();
}

/**************************************************************************************/
/*                     CONFIGURE HIGH GRAPH AND SET THE TIMER                         */
/**************************************************************************************/

void ShowGraphs::HighGraphTimer() {
    mainUi->HighTimeGraph->plotLayout()->insertRow(0);
    mainUi->HighTimeGraph->plotLayout()->addElement(0, 0, new QCPTextElement(mainUi->HighTimeGraph, "High Values", QFont("sans", 12, QFont::Bold)));

    mainUi->HighTimeGraph->addGraph(mainUi->HighTimeGraph->xAxis, mainUi->HighTimeGraph->yAxis);
    mainUi->HighTimeGraph->graph(0)->setName("Threshold");
    mainUi->HighTimeGraph->graph(0)->setPen(QPen(Qt::blue));

    mainUi->HighTimeGraph->addGraph(mainUi->HighTimeGraph->xAxis, mainUi->HighTimeGraph->yAxis);
    mainUi->HighTimeGraph->graph(1)->setName("High (mm)");
    mainUi->HighTimeGraph->graph(1)->setPen(QPen(Qt::red));

    mainUi->HighTimeGraph->legend->setVisible(true);
    mainUi->HighTimeGraph->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    mainUi->HighTimeGraph->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight | Qt::AlignTop);

    mainUi->HighTimeGraph->xAxis->setLabel("Time (seconds)");
    mainUi->HighTimeGraph->yAxis->setLabel("High (mm)");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateHighGraph()));
    timer->start(1000);
}


/**************************************************************************************/
/*                     REFRESH HIGH VALUE ON THE HIGH GRAPH                           */
/**************************************************************************************/

void ShowGraphs::updateHighGraph() {
    bool highOk;
    double highValue = mainUi->highValueLbl->text().toDouble(&highOk);

    if (highOk) {
        QCPGraph *thresholdGraph = mainUi->HighTimeGraph->graph(0);
        int thresholdDataCount = thresholdGraph->dataCount();
        thresholdGraph->addData(thresholdDataCount, threshold);
        mainUi->HighTimeGraph->yAxis->rescale(true);

        QCPGraph *highGraph = mainUi->HighTimeGraph->graph(1);
        int highDataCount = highGraph->dataCount();
        highGraph->addData(highDataCount, highValue);
        mainUi->HighTimeGraph->yAxis->rescale(true);
    }

    int dataCount = std::max(mainUi->HighTimeGraph->graph(0)->dataCount(), mainUi->HighTimeGraph->graph(1)->dataCount());
    mainUi->HighTimeGraph->xAxis->setRange(dataCount - 10, dataCount);

    mainUi->HighTimeGraph->replot();
}



/**************************************************************************************/
/*                     CONFIGURE POWER GRAPH AND SET THE TIMER                        */
/**************************************************************************************/

void ShowGraphs::PowerGraphTimer() {
    mainUi->PowerTimeGraph->addGraph();
    mainUi->PowerTimeGraph->plotLayout()->insertRow(0);
    mainUi->PowerTimeGraph->plotLayout()->addElement(0, 0, new QCPTextElement(mainUi->PowerTimeGraph, "Power values", QFont("sans", 12, QFont::Bold)));
    mainUi->PowerTimeGraph->xAxis->setLabel("Time (seconds)");
    mainUi->PowerTimeGraph->yAxis->setLabel("Power (watt)");
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePowerGraph()));
    timer->start(1000);
}

/**************************************************************************************/
/*                     REFRESH POWER VALUE ON THE POWER GRAPH                         */
/**************************************************************************************/

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

/**************************************************************************************/
/*                  CONFIGURE POWER/HIGH GRAPH AND SET THE TIMER                      */
/**************************************************************************************/

void ShowGraphs::PowerHighGraphTimer() {
    mainUi->PowerHighGraph->plotLayout()->insertRow(0);
    mainUi->PowerHighGraph->plotLayout()->addElement(0, 0, new QCPTextElement(mainUi->PowerHighGraph, "Power/High Graph", QFont("sans", 12, QFont::Bold)));

    mainUi->PowerHighGraph->addGraph(mainUi->PowerHighGraph->xAxis, mainUi->PowerHighGraph->yAxis);
    mainUi->PowerHighGraph->graph(0)->setName("Power (watt)");
    mainUi->PowerHighGraph->graph(0)->setPen(QPen(Qt::blue));

    mainUi->PowerHighGraph->addGraph(mainUi->PowerHighGraph->xAxis, mainUi->PowerHighGraph->yAxis2);
    mainUi->PowerHighGraph->graph(1)->setName("High (mm)");
    mainUi->PowerHighGraph->graph(1)->setPen(QPen(Qt::red));

    mainUi->PowerHighGraph->legend->setVisible(true);
    mainUi->PowerHighGraph->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    mainUi->PowerHighGraph->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight | Qt::AlignTop);

    mainUi->PowerHighGraph->xAxis->setLabel("Time (seconds)");
    mainUi->PowerHighGraph->yAxis->setLabel("Power (watt)");
    mainUi->PowerHighGraph->yAxis2->setLabel("High (mm)");

    mainUi->PowerHighGraph->yAxis2->setVisible(true);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePowerHighGraph()));
    timer->start(1000);
}

/**************************************************************************************/
/*               REFRESH HIGH AND POWER VALUES ON THE HIGH/POWER GRAPH                */
/**************************************************************************************/

void ShowGraphs::updatePowerHighGraph() {
    bool powerOk;
    double powerValue = mainUi->PowerValueLbl->text().toDouble(&powerOk);
    if (powerOk) {
        QCPGraph *powerGraph = mainUi->PowerHighGraph->graph(0);
        int powerDataCount = powerGraph->dataCount();
        powerGraph->addData(powerDataCount, powerValue);
        mainUi->PowerHighGraph->yAxis->rescale(true);
    }

    bool highOk;
    double highValue = mainUi->highValueLbl->text().toDouble(&highOk);
    if (highOk) {
        QCPGraph *highGraph = mainUi->PowerHighGraph->graph(1);
        int highDataCount = highGraph->dataCount();
        highGraph->addData(highDataCount, highValue);
        mainUi->PowerHighGraph->yAxis2->rescale(true);
    }

    int dataCount = std::max(mainUi->PowerHighGraph->graph(0)->dataCount(), mainUi->PowerHighGraph->graph(1)->dataCount());
    mainUi->PowerHighGraph->xAxis->setRange(dataCount - 10, dataCount);

    mainUi->PowerHighGraph->replot();
}

/**************************************************************************************/
/*                    DRAW CONSTANT LINE ON HIGH TIME GRAPH                           */
/**************************************************************************************/

void ShowGraphs::drawConstantLine(int value) {
    threshold = value;
}
