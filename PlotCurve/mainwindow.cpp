#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomPlot.h"
#include <time.h>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupgraph(ui->customPlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupgraph(QCustomPlot *customPlot)
{
    srand(time(NULL));
    QVector<double> x(6), y(101); // initialize with entries 0..100
    for(int j=1; j<=5; j++)
    {
        x[j]=j;       // ID NUMBER goes from 1 to 5
    }
    for (int i=0; i<101; ++i)
    {
      y[i] = rand()%100+1; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("Student ID");
    customPlot->yAxis->setLabel("Score");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(1, 5);
    customPlot->yAxis->setRange(0, 100);
    customPlot->replot();
}
