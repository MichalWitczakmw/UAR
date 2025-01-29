#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtCharts>
#include <QTimer>


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
    void aktualizujWartosciObliczonejLayout();
    void aktualizujUchybLayout();
    void aktualizujRegulatorLayout();
private slots:
    void on_ZakonczProgram_clicked();

    void on_OkienkoZapiszPlik_clicked();

    void on_StartWykresom_clicked();

    void on_Reset_clicked();

    void on_StopWykresom_clicked();

private:
    Ui::MainWindow *ui;
    //Sprzezenie * sprzerzenieZwrotne;
    //Regulator * regulPID;
    //ModelARX * modelARX;
    //Generator * generatorSygnalow;

    QLineSeries * seria = nullptr;
    QLineSeries * seriaWartosciZadanej = nullptr;

    QChart * chart = nullptr;
    QChartView * chartview = nullptr;
    QTimer *timer = nullptr;

    RobieWykres * wykresy = nullptr;
    //RobieWykres * wykresWartosciWyjsciowej = nullptr;
    //RobieWykres * wykresUchyb = nullptr;
    //RobieWykres *  wykresRegulatoraPID = nullptr;

    deque<double> a = {0.6};
    deque<double> b = {0.4};

    double Kp =1;
    double Ti = 0.5;
    double Td = 0.4;

    double wartoscZadana = 10;
    double wartoscZaklocenia = 1;

    bool niebylo= true;
};
#endif // MAINWINDOW_H
