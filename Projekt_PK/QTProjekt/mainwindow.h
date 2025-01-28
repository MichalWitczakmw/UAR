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
#include "../Projekt_PK/Robie_Wykres.h"

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

private slots:
    void on_ZakonczProgram_clicked();

    void on_OkienkoZapiszPlik_clicked();

    void on_StartWykresom_clicked();

    void on_StopWykresom_clicked();

    void on_Reset_clicked();

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
    RobieWykres * wykresWartosciWyjsciowej;
    RobieWykres * wykresUchybu;
    RobieWykres *  wykresRegulatoraPID;
    deque<double> a = {0.6};
    deque<double> b = {0.4};
    double Kp =1;
    double Ti = 0.5;
    double Td = 0.4;
    double wartoscZadana;
    double wartoscZaklocenia;
};
#endif // MAINWINDOW_H
