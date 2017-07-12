#include "dialognewperson.h"
#include "ui_dialognewperson.h"

DialogNewPerson::DialogNewPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewPerson)
{
    ui->setupUi(this);
}

DialogNewPerson::~DialogNewPerson()
{
    delete ui;
}
