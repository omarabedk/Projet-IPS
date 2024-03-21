#ifndef SHOWGRAPHS_H
#define SHOWGRAPHS_H

#include <QObject>
#include "mainwindow.h"

class ShowGraphs : public QObject
{
    Q_OBJECT
public:
    ShowGraphs(Ui::MainWindow *ui);
    void RealTimePlotter(Ui::MainWindow *ui);
public slots:
    void updateGraph(Ui::MainWindow *ui);
private:

};


#endif // SHOWGRAPHS_H
