#ifndef SHOWGRAPHS_H
#define SHOWGRAPHS_H

#include <QObject>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class ShowGraphs : public QObject
{
    Q_OBJECT
public:
    ShowGraphs(Ui::MainWindow *ui);
    void HighGraphTimer();
    void PowerGraphTimer();
public slots:
    void updateHighGraph();
    void updatePowerGraph();
private:
    Ui::MainWindow *mainUi;
};


#endif // SHOWGRAPHS_H
