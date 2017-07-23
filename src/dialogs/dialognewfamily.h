//===============================================
// Name        : dialognewfamily.h
// Author      : Michael Louie
// Description : Header for the new family dialog
//===============================================
#ifndef DIALOGNEWFAMILY_H
#define DIALOGNEWFAMILY_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class DialogNewFamily;
}

class DialogNewFamily : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewFamily(QWidget *parent = 0);
    ~DialogNewFamily();
    bool accepted;
    string getFamilyName();
    string getFamilyDescription();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogNewFamily *ui;
    string familyName;
    string familyDesc;
};

#endif // DIALOGNEWFAMILY_H
