#include "dialognewfamily.h"
#include "ui_dialognewfamily.h"

DialogNewFamily::DialogNewFamily(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewFamily)
{
    ui->setupUi(this);
}

DialogNewFamily::~DialogNewFamily()
{
    delete ui;
}
