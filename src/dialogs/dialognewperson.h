#ifndef DIALOGNEWPERSON_H
#define DIALOGNEWPERSON_H

#include <QDialog>

namespace Ui {
class DialogNewPerson;
}

class DialogNewPerson : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewPerson(QWidget *parent = 0);
    ~DialogNewPerson();

private:
    Ui::DialogNewPerson *ui;
};

#endif // DIALOGNEWPERSON_H
