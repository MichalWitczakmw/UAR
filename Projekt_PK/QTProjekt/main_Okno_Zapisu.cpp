#include "main_Okno_Zapisu.h"
#include "ui_main_Okno_Zapisu.h"

mainOknoZapisu::mainOknoZapisu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainOknoZapisu)
{
    ui->setupUi(this);
}

mainOknoZapisu::~mainOknoZapisu()
{
    delete ui;
}

void mainOknoZapisu::on_ZamknijZapis_clicked()
{
    this->close();
}

