//============================================================================
// Name        : dialog.cpp
// Author      : Michael Louie
// Description : Contains logic for all dialog-related UI.
//============================================================================
#include "dialog.h"
#include "ui_aboutdialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


// About Dialog
aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
}

aboutDialog::~aboutDialog()
{
    delete ui;
}

void aboutDialog::on_pushButton_clicked()
{
    close();
}
