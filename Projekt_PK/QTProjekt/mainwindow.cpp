#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    seria = new QLineSeries();

    regulPID = new Regulator(1,0.1,0.1);
    deque<double> a = {0.4};
    deque<double> b = {0.6};
    sprzerzenieZwrotne = new Sprzezenie(a,b,1,*regulPID,JakiSygnal::Sinusoidalny,10.5);
    seria->append(0,sprzerzenieZwrotne->Symuluj(currentTime));


    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(seria);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(-40,40);
    chart->axes(Qt::Horizontal).first()->setRange(0,50);

    chart->setVisible(true);

    chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setVisible(true);

    setCentralWidget(chartview);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateChart);
    timer->start(200);

}

void MainWindow::updateChart()
{
    // Aktualizacja wartości czasu
    currentTime++;

    // Symulacja nowej wartości i dodanie jej do serii
    double newValue = sprzerzenieZwrotne->Symuluj(currentTime);
    seria->append(currentTime, newValue);

    // Utrzymywanie zakresu osi X
    if (currentTime > 50) {
        seria->remove(0); // Usunięcie pierwszego punktu
        chartview->chart()->axes(Qt::Horizontal).first()->setRange(currentTime - 50, currentTime);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete sprzerzenie;
    //delete regulPID;
}
