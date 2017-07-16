//================================================
// Name        : angena.cpp
// Author      : Michael Louie
// Description : Controller for primary UI window.
//================================================
#include <QDebug>

#include "angena.h"
#include "ui_angena.h"

Angena::Angena(QWidget *parent) : QMainWindow(parent), ui(new Ui::Angena)
{
    ui->setupUi(this);
    Model m;
    Dialog d;
}

Angena::~Angena() { delete ui; }

/////////////////////////////////
//
//  Context menu button actions.
//
/////////////////////////////////

/*
 * Creates new family tree.
 */
void Angena::on_actionNew_triggered()
{
    qDebug() << "Creating new tree.";

    // If there is another tree open currently, prompt for save/close.
    if (m.isTreeOpen()) {
        d.showSaveConfirmationDialog();
    }

    d.showNewFamilyTreeDialog();
    // If has info, then overwrite model with new open tree state and clear/update view
    // Else do nothing.

    Angena::clearGraphicsView();
}

/*
 * Opens existing family tree.
 * Input (dialog): filename - selected file name from file dialog.
 */
void Angena::on_actionOpen_triggered()
{
    qDebug() << "Opening new tree.";

    // If there is another tree open currently, prompt for save/close.
    if (m.isTreeOpen()) {
        d.showSaveConfirmationDialog();
    }

    // If not cancelled, do nothing.
    // Else continue.

    // Browse for tree file.
    QString filename = QFileDialog::getOpenFileName(this, "C://", "GEDCOM (*.txt)");
    qDebug() << filename;
    if (filename != NULL) {
        // Extract tree state from file.

        // Set family tree state to reflect the retrieved state.

        // Update graphic view

    }
}

/*
 * Commits family tree state to an existing/opened file.
 */
void Angena::on_actionSave_triggered()
{
    qDebug() << "Saving new tree state.";
    // Only enable if there is a change or undo resolved to original state
    // Does not apply for now...
    QUuid newId = QUuid::createUuid();
    qDebug() << newId;

    // If a file does not exist, call save_as() and retrieve a file name/path
    // Save tree state to file path.
    // Update save status bar.
}

/*
 * Saves family tree state to a new file.
 * Displays dialog to determine save file path in GEDCOM format to disk.
 * Also called by other functions.
 */
void Angena::on_actionSave_As_triggered()
{
    qDebug() << "Saving new tree state as...";
    // TODO: Dialog box.
    // TODO: Call the writer to generate GEDCOM based on family tree state.
}

/*
 * Closes currently opened family tree.
 */
void Angena::on_actionClose_triggered()
{
    // TODO: Prompt save if tree state has changed.
    // TODO: Or prompt save as if file never existed.
    qDebug() << "Closing tree.";
    // Nullify model tree state.
    // Free memory.
    // Update display.
    // Disable necessary inputs.
}

/*
 * Opens previously opened tree states.
 * Input: recentTree - clicked filename from recent files menu.
 */
// TODO: How should I keep track of recently opened file during runtime and after closing?
void Angena::on_actionRecent_Files_triggered()
{
    // If there were not any recently opened file, then throw an error (change return type?).
    // The menu link should not have been enabled in the first place.
    qDebug() << "Opening recent file";
    // Open the tree state, update model tree state.
    // Update display
    // NOTE: Method not implemented!
}

/*
 * Prints current tree state visualization.
 */
void Angena::on_actionPrint_triggered()
{
    qDebug() << "Printing state of tree display.";
    // TODO: Implement printing functionality. Probably another dialog following
    // standard printing functionality such as choose printer, size, layout, etc...
}

/*
 * Terminates Angena application.
 */
void Angena::on_actionExit_triggered()
{
    qDebug() << "Shutting application down.";
    // TODO: Prompt save if tree state has changed.
    close();
    // TODO: Destroy stuff as needed.
}

/*
 * Displays preferences/settings prompt.
 */
void Angena::on_actionPreferences_triggered()
{
    // Show the preferences dialog.
    // On Save, commit to model, close dialog
    // On cancel, close dialog
}

/*
 * Displays dialog regarding simple information about Angena.
 */
void Angena::on_actionAbout_triggered()
{
    d.showAboutDialog();
}

///////////////////////
//
//  Tool button actions
//
///////////////////////

/*
 * Reverts to previous tree state before change.
 */
void Angena::on_actionUndo_triggered()
{
    qDebug() << "Undo!";
    // NOTE: Method not implemented!
}

/*
 * Returns tree state to next more recent version. Usually after undone.
 */
void Angena::on_actionRedo_triggered()
{
    qDebug() << "Redo!";
    // NOTE: Method not implemented!
}

/*
 * Adds new person to the current tree state.
 */
void Angena::on_actionAdd_Person_triggered()
{
    qDebug() << "Add!";
    // Add person dialog
    // Retrieve all information
    // Pass to model
}

/*
 * Removes selected person from the current tree state.
 */
void Angena::on_actionRemove_Person_triggered()
{
    qDebug() << "Remove!";
    // Get currently selected person.
    // If selected, continue, else throw exception (option should be disabled).
    // Open dialog
    // On Cancel, remove dialog
    // On Ok, commit to model, remove dialog, update view.
}

/*
 * Edits selected person in the current tree state.
 */
void Angena::on_actionEdit_Person_triggered()
{
    qDebug() << "Edit!";
    // Get currently selected person.
    // If selected, continue, else throw exception (option should be disabled).
    // Open dialog
    // On Cancel, remove dialog
    // On Ok, commit to model, remove dialog, update view.
}

////////////////////
//
//  Internal Actions
//
////////////////////

/*
 * Redraws graphic view to reflect current tree state.
 */
void Angena::redrawGraphicsView()
{
    qDebug() << "Redraw!";
    // Referencing model, pull data and draw each person.
}

/*
 * Clears graphic view to reflect empty tree state.
 */
void Angena::clearGraphicsView()
{
    qDebug() << "Clear!";
    // Clear graphics view.
}
