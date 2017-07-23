//===============================================
// Name        : angena.h
// Author      : Michael Louie
// Description : Header for many UI interactions.
//===============================================
#ifndef ANGENA_H
#define ANGENA_H

#include <QMainWindow>
#include <QFileDialog>

#include <vector>
#include <string>

#include "model/model.h"
#include "dialogs/dialog.h"

namespace Ui {
    class Angena;
}

class Angena : public QMainWindow
{
    Q_OBJECT
    public:
        explicit Angena(QWidget *parent = 0);
        ~Angena();

    private:
        Ui::Angena *ui;
        Model m;
        Dialog d;

    private slots:
        void on_actionNewFamily_triggered();
        void on_actionOpen_triggered();
        void on_actionSave_triggered();
        void on_actionSave_As_triggered();
        void on_actionAbout_triggered();
        void on_actionClose_triggered();
        void on_actionPrint_triggered();
        void on_actionExit_triggered();
        void on_actionUndo_triggered();
        void on_actionRedo_triggered();
        void on_actionAdd_Person_triggered();
        void on_actionRemove_Person_triggered();
        void redrawGraphicsView();
        void clearGraphicsView();
        void on_pushButtonSavePerson_clicked();

};

#endif // ANGENA_H
