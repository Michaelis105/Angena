//==========================================================================
// Name        : dialognewfamily.cpp
// Author      : Michael Louie
// Description : Model storing new family information user input for model
//               to pull.
//==========================================================================
#include "dialognewfamily.h"
#include "ui_dialognewfamily.h"
#include <QDebug>

DialogNewFamily::DialogNewFamily(QWidget *parent) : QDialog(parent), ui(new Ui::DialogNewFamily)
{
    ui->setupUi(this);
}

DialogNewFamily::~DialogNewFamily() { delete ui; }


void DialogNewFamily::on_buttonBox_accepted()
{
    qDebug() << "ACCEPTED!";
    accepted = true;
    familyName = ui->lineEditFamilyTreeName->text().toStdString();
    if (familyName.size() == 0) {
        this->reject();
    }
    familyDesc = ui->lineEditFamilyTreeName->text().toStdString();
}


void DialogNewFamily::on_buttonBox_rejected()
{
    accepted = false;
    familyName.clear();
    familyDesc.clear();

}

string DialogNewFamily::getFamilyName() {
    return familyName;
}

string DialogNewFamily::getFamilyDescription() {
    return familyDesc;
}
