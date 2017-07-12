#ifndef DIALOGSAVECONFIRMATION_H
#define DIALOGSAVECONFIRMATION_H

#include <QDialog>

namespace Ui {
    class DialogSaveConfirmation;
}

class DialogSaveConfirmation : public QDialog
{
    Q_OBJECT

    public:
        explicit DialogSaveConfirmation(QWidget *parent = 0);
        ~DialogSaveConfirmation();

    private:
        Ui::DialogSaveConfirmation *ui;
};

#endif // DIALOGSAVECONFIRMATION_H
