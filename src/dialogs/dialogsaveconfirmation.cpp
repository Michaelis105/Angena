//==================================================================
// Name        : dialognewfamily.cpp
// Author      : Michael Louie
// Description : Dialog storing user decision for unsaved tree state
//==================================================================
#include "dialogsaveconfirmation.h"
#include "ui_dialogsaveconfirmation.h"

DialogSaveConfirmation::DialogSaveConfirmation(QWidget *parent) : QDialog(parent), ui(new Ui::DialogSaveConfirmation)
{
    ui->setupUi(this);
    saveAction = 3;
}

DialogSaveConfirmation::~DialogSaveConfirmation() { delete ui; }

void DialogSaveConfirmation::on_pushButtonSave_clicked() { saveAction = 0; }

void DialogSaveConfirmation::on_pushButtonSaveAs_clicked() { saveAction = 1; }

void DialogSaveConfirmation::on_pushButtonDoNotSave_clicked() { saveAction = 2; }

void DialogSaveConfirmation::on_pushButtonCancel_clicked() { saveAction = 3; }
