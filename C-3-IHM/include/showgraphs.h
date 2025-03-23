#ifndef SHOWGRAPHS_H
#define SHOWGRAPHS_H

#include <QObject>

#include "ui_mainwindow.h"

class ShowGraphs : public QObject
{
    Q_OBJECT
public:
    ShowGraphs(Ui::MainWindow *ui);
    void HighGraphTimer();
    void PowerGraphTimer();
    void PowerHighGraphTimer();
    void drawConstantLine(int value);

public slots:
    void updateHighGraph();
    void updatePowerGraph();
    void updatePowerHighGraph();

private:
    QCPGraph *constantLineGraph;
    Ui::MainWindow *mainUi;
    int threshold = NULL;
};


#endif // SHOWGRAPHS_H
