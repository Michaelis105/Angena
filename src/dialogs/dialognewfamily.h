#ifndef DIALOGNEWFAMILY_H
#define DIALOGNEWFAMILY_H

#include <QDialog>

namespace Ui {
class DialogNewFamily;
}

class DialogNewFamily : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewFamily(QWidget *parent = 0);
    ~DialogNewFamily();

private:
    Ui::DialogNewFamily *ui;
};

#endif // DIALOGNEWFAMILY_H
