//============================================================================
// Name        : angena.cpp
// Author      : Michael Louie
// Description : Controller and primary window for UI.
//============================================================================
#include "angena.h"
#include "ui_angena.h"
#include "dialog.h"
#include "model.h"
#include <QFileDialog>
// TODO: Get rid of debugging include at release.
#include <QDebug>

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
    qInfo() << "Creating new tree.";
    // If there is another tree open currently, prompt for save/close.
    // Pop up display.
    // Ask tree name.
    // other settings.
    // Overwrite model with new open tree state.
}

/*
 * Opens previously opened
 * Input (dialog): filename - selected file name from file dialog.
 */
void Angena::on_actionOpen_triggered()
{
    qInfo() << "Opening new tree.";
    // If there is another tree open currently, prompt for save/close.
    // Browse for tree file.
    QString filename = QFileDialog::getOpenFileName(this, "C://", "GEDCOM (*.txt)");
    qInfo() << filename;
    // Extract tree state from file.
    // Set family tree state to reflect the retrieved state.
}

/*
 * Commits family tree state to a file.
 */
void Angena::on_actionSave_triggered()
{
    qInfo() << "Saving new tree state.";
    // Only enable if there is a change or undo resolved to original state.
    // If a file does not exist, call save_as() and retrieve a file name/path
    // Save tree state to file path.
}

/*
 * Displays dialog to determine family tree name and save file path in GEDCOM format.
 */
void Angena::on_actionSave_As_triggered()
{
    qInfo() << "Saving new tree state as...";
    // TODO: Dialog box.
    // TODO: Call the writer to generate GEDCOM based on family tree state.
}

/*
 * Displays dialog regarding simple information about Angena.
 */
void Angena::on_actionAbout_triggered()
{
    aboutDialog ad;
    ad.setModal(true);
    ad.exec();
}

/*
 * Closes currently opened family tree
 */
void Angena::on_actionClose_triggered()
{
    // TODO: Prompt save if tree state has changed.
    qInfo() << "Closing tree.";
}

/*
 * Opens previously opened
 * Input: recentTree - clicked filename from recent files menu.
 */
// TODO: How should I keep track of recently opened file during runtime and after closing?
void Angena::on_actionRecent_Files_triggered()
{
    // If there were not any recently opened file, then throw an error (change return type?).
    // The menu link should not have been enabled in the first place.
    qInfo() << "Opening recent file";

}

// TODO: Linked only to CUT button, add other tool buttons from UI and change
// this function name to something specific.
void Angena::on_toolButton_clicked()
{
    qInfo() << "tool button clicked";
}

// TODO: Implement other tool button methods.

// TODO: Implement printing functionality. Probably another dialog following
// standard printing functionality such as choose printer, size, layout, etc...
void Angena::on_actionPrint_triggered()
{
    qInfo() << "Printing state of tree display.";
    // TODO: Implement print dialog.
}

void Angena::on_actionExit_triggered()
{
    qInfo() << "Shutting application down.";
    // TODO: Prompt save if tree state has changed.
    close();
    // TODO: Destroy stuff as needed.
}
