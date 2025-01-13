#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtCharts>
#include <QTimer>


#include "../Projekt_PK/Generator_Sygnalow.h"
#include "../Projekt_PK/Model_ARX.h"
#include "../Projekt_PK/Regulator_PID.h"
#include "../Projekt_PK/Sprzerzenie_Zwrotne.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Sprzezenie * sprzerzenieZwrotne;
    Regulator * regulPID;
    ModelARX * modelARX;
    Generator * generatorSygnalow;
    QLineSeries * seria;
    QChart * chart;
    QChartView * chartview;
    QTimer *timer;

    int currentTime;

    void updateChart();
};
#endif // MAINWINDOW_H
