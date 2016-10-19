//============================================================================
// Name        : angena.cpp
// Author      : Michael Louie
// Description : Controller and primary window for UI.
//============================================================================
#include "angena.h"
#include "ui_angena.h"
#include "dialog.h"
#include "model.h"
#include <QDebug>
#include <QFileDialog>

Angena::Angena(QWidget *parent) : QMainWindow(parent), ui(new Ui::Angena)
{
    ui->setupUi(this);
    model m;
}

Angena::~Angena()
{
    delete ui;
}

void Angena::on_actionNew_triggered()
{
    // Pop up display.
    // Ask tree name.
    // other settings.
    qInfo() << "Creating new tree.";
}

void Angena::on_actionOpen_triggered()
{
    // Browse for tree file.
    qInfo() << "Opening new tree.";
    QString filename = QFileDialog::getOpenFileName(this, "C://", "GEDCOM (*.txt)");
    qInfo() << filename;
}

void Angena::on_actionSave_triggered()
{
    // Only enable if there is a change or undo resolved to original state.
    // Save state of tree.
    qInfo() << "Saving new tree state.";
}

void Angena::on_actionSave_As_triggered()
{
    // Dialog box.
    qInfo() << "Saving new tree state as...";
}

void Angena::on_actionAbout_triggered()
{
    qInfo() << "About clicked, displaying about.";
    aboutDialog ad;
    ad.setModal(true);
    ad.exec();
}

void Angena::on_actionClose_triggered()
{
    qInfo() << "Closing tree.";
}

void Angena::on_actionRecent_Files_triggered()
{
    // If there was a recently open file, enable.
    qInfo() << "Opening recent file";

}

void Angena::on_toolButton_clicked()
{
    // ???
    qInfo() << "tool button clicked";
}

void Angena::on_actionPrint_triggered()
{
    qInfo() << "Printing state of tree display.";
}

void Angena::on_actionExit_triggered()
{
    // Prompt save.
    qInfo() << "Shutting application down.";
    close();
}
