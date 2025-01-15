#ifndef MAIN_OKNO_ZAPISU_H
#define MAIN_OKNO_ZAPISU_H

#include <QDialog>

namespace Ui {
class mainOknoZapisu;
}

class mainOknoZapisu : public QDialog
{
    Q_OBJECT

public:
    explicit mainOknoZapisu(QWidget *parent = nullptr);
    ~mainOknoZapisu();

private slots:
    void on_ZamknijZapis_clicked();

private:
    Ui::mainOknoZapisu *ui;
};

#endif // MAIN_OKNO_ZAPISU_H
