#include "dialogsaveconfirmation.h"
#include "ui_dialogsaveconfirmation.h"

DialogSaveConfirmation::DialogSaveConfirmation(QWidget *parent) : QDialog(parent), ui(new Ui::DialogSaveConfirmation)
{
    ui->setupUi(this);
}

DialogSaveConfirmation::~DialogSaveConfirmation()
{
    delete ui;
}

void DialogSaveConfirmation::on_pushButtonSave_clicked()
{

}

void DialogSaveConfirmation::on_pushButtonSaveAs_clicked()
{

}

void DialogSaveConfirmation::on_pushButtonDoNotSave_clicked()
{

}

void DialogSaveConfirmation::on_pushButtonCancel_clicked()
{

}
