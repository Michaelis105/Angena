//============================================================================
// Name        : dialog.h
// Author      : Michael Louie
// Description : Header for many dialog interactions.
//============================================================================
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    public:
        explicit Dialog(QWidget *parent = 0);
        ~Dialog();

    private:
        Ui::Dialog *ui;
};

#endif // DIALOG_H


#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
    class aboutDialog;
}

class aboutDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit aboutDialog(QWidget *parent = 0);
        ~aboutDialog();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::aboutDialog *ui;
};

#endif // ABOUTDIALOG_H

#ifndef NEWFAMILYTREE_H
#define NEWFAMILYTREE_H

#include <QDialog>

namespace Ui {
    class newfamilytree;
}

class newfamilytree : public QDialog
{
    Q_OBJECT

    public:
        explicit newfamilytree(QWidget *parent = 0);
        ~newfamilytree();

    private:
        Ui::newfamilytree *ui;
};

#endif // NEWFAMILYTREE_H

