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
