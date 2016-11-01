//============================================================================
// Name        : angena.h
// Author      : Michael Louie
// Description : Header for many UI interactions.
//============================================================================
#ifndef ANGENA_H
#define ANGENA_H

#include <QMainWindow>

namespace Ui {
class Angena;
}

class Angena : public QMainWindow
{
    Q_OBJECT

    public:
        explicit Angena(QWidget *parent = 0);
        ~Angena();

    private slots:
        void on_actionNew_triggered();

        void on_actionOpen_triggered();

        void on_actionSave_triggered();

        void on_actionSave_As_triggered();

        void on_actionAbout_triggered();

        void on_actionClose_triggered();

        void on_actionRecent_Files_triggered();

        void on_actionPrint_triggered();

        void on_actionExit_triggered();

        void on_actionPreferences_triggered();

        void on_actionUndo_triggered();

        void on_actionRedo_triggered();

        void on_actionAdd_Person_triggered();

        void on_actionRemove_Person_triggered();

        void on_actionEdit_Person_triggered();

        void on_actionPedigree_triggered();

        void on_actionHyperbolic_triggered();

        void on_actionFan_triggered();

private:
        Ui::Angena *ui;
};

#endif // ANGENA_H
