#include "Zapisze_Do_Pliku.h"
#include <QFile>
#include <QMessageBox>
#include <assert.h>
#include <QTextStream>
#include <QDebug>
#include <deque>
#include <QDir>

void  ZapiszeDoPliku::zapiszBinarnie()
{


}

void ZapiszeDoPliku::zapiszTekstowo(double KP, double TI, double TD,double WZ,double ZK,int I,deque<double> a,deque<double> b,int jaki, QString sciezka)
{
    qDebug() << "Ścieżka pliku: " << sciezka;
    QFile plik(sciezka);
    QFileInfo infoPliku(plik);

    // Sprawdzamy, czy katalog docelowy istnieje
    QDir katalog = infoPliku.absoluteDir();
    if (!katalog.exists()) {
        qDebug() << "Katalog docelowy nie istnieje: " << katalog.path();
        if (!katalog.mkpath(katalog.path())) {
            qWarning() << "Nie można utworzyć katalogu! Sprawdź uprawnienia.";
            return;
        } else {
            qDebug() << "Katalog został utworzony.";
        }
    }
    if (plik.exists()) {
        qDebug() << "Plik już istnieje.";
    } else {
        qDebug() << "Plik nie istnieje. Spróbuję go utworzyć.";
    }

    // Otwieramy plik do zapisu (lub tworzymy nowy)
    if (!plik.open(QFile::WriteOnly | QFile::Text)) {
        qWarning() << "Nie można otworzyć pliku do zapisu: " << sciezka;
        qWarning() << "Błąd: " << plik.errorString();
        return;
    }
    QTextStream dane(&plik);

    // Zapisywanie wartości PID
    dane << "Wartosc zadana: " << QString::number(WZ)
         << "\nZaklocenie: "<<QString::number(ZK)
         << "\nInterwal: "<<QString::number(I)
         << "\nJaki Sygnał: "<<QString::number(jaki)
         << "Nastawy regulatora PID:\n"
         << "\tKp: " << QString::number(KP)
         << "\tTi: " << QString::number(TI)
         << "\tTd: " << QString::number(TD) << "\n";

    // Zapisywanie deque 'a'
    dane << "Wartości a: ";
    for (double val : a) {
        dane << QString::number(val) << " ";
    }
    dane << "\n";

    // Zapisywanie deque 'b'
    dane << "Wartości b: ";
    for (double val : b) {
        dane << QString::number(val) << " ";
    }
    dane << "\n";

    plik.flush();
    plik.close();
}

void ZapiszeDoPliku::wczytajTekstowo(double &KP, double &TI, double &TD, double &WZ, double &ZK, int &I, std::deque<double> &a, std::deque<double> &b, int &jaki, QString sciezka)
{
    QFile plik(sciezka);

    if (!plik.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << "Nie można otworzyć pliku: " << sciezka;
        return;
    }

    QTextStream dane(&plik);
    QString linia;

    while (!dane.atEnd()) {
        linia = dane.readLine();

        if (linia.startsWith("Wartosc zadana:")) {
            WZ = linia.split(": ")[1].toDouble();
        } else if (linia.startsWith("Zaklocenie:")) {
            ZK = linia.split(": ")[1].toDouble();
        } else if (linia.startsWith("Interwal:")) {
            I = linia.split(": ")[1].toInt();
        } else if (linia.startsWith("Jaki Sygnał:")) {
            jaki = linia.split(": ")[1].toInt();
        } else if (linia.startsWith("\tKp:")) {
            QStringList pidValues = linia.split("\t");
            if (pidValues.size() >= 3) {
                KP = pidValues[0].split(": ")[1].toDouble();
                TI = pidValues[1].split(": ")[1].toDouble();
                TD = pidValues[2].split(": ")[1].toDouble();
            }
        } else if (linia.startsWith("Wartości a:")) {
            a.clear();
            QStringList values = linia.mid(10).split(" ");
            for (const QString &val : values) {
                if (!val.isEmpty()) a.push_back(val.toDouble());
            }
        } else if (linia.startsWith("Wartości b:")) {
            b.clear();
            QStringList values = linia.mid(10).split(" ");
            for (const QString &val : values) {
                if (!val.isEmpty()) b.push_back(val.toDouble());
            }
        }
    }

    plik.close();
}
