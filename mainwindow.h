#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtCharts>
#include <QTimer>


#include "Robie_Wykres.h"

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

    deque<double> pobierzWspolczynnikiA();
    deque<double> pobierzWspolczynnikiB();

private slots:
    void on_ZakonczProgram_clicked();

    void on_OkienkoZapiszPlik_clicked();

    void on_StartWykresom_clicked();

    void on_Reset_clicked();

    void on_StopWykresom_clicked();

    void on_wartoscKP_valueChanged(double kp);

    void on_wartoscTI_valueChanged(double ti);

    void on_wartoscTD_valueChanged(double td);

    void on_sygnalSkokowy_cliked(bool checked);

    void on_sygnalSinuoidalny_cliked(bool checked);

    void on_sygnalProstokatny_cliked(bool checked);


    void on_wartoscWynik_valueChanged(double zadana);

    void on_wartoscIntewal_valueChanged(int wi);

    void on_wartoscZaklocenia_valueChanged(int zaklocenie);

    void on_groupBox_clicked();

    void on_wartosc_valueChanged();

    void on_ZapiszPrzycisk_clicked();

    void on_WycztajPrzycisk_clicked();

private:
    Ui::MainWindow *ui;

    QLineSeries * seria = nullptr;
    QLineSeries * seriaWartosciZadanej = nullptr;

    QChart * chart = nullptr;
    QChartView * chartview = nullptr;
    QTimer *timer = nullptr;

    RobieWykres * wykresy = nullptr;


    deque<double> a = {0.6, 0.0, 0.0, 0.0};
    deque<double> b = {0.4, 0.0, 0.0, 0.0};

    double Kp =1;
    double Ti = 0.5;
    double Td = 0.4;

    double wartoscZadana = 10;
    double wartoscZaklocenia = 1;

    int wartoscInterwalu = 100;
    int jakanastawa;

    JakiSygnal chceSygnal = JakiSygnal::Skokowy;

    bool niebylo= true;


};
#endif // MAINWINDOW_H
