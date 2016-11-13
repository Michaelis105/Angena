//============================================================================
// Name        : angena.cpp
// Author      : Michael Louie
// Description : Primary controller for primary UI window.
//============================================================================
#include "angena.h"
#include <QDebug> // TODO: Get rid of debugging include at release.

Angena::Angena(QWidget *parent) : QMainWindow(parent), ui(new Ui::Angena)
{
    ui->setupUi(this);
    model m;
    // TODO: Open settings file.
}

Angena::~Angena()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Context menu button actions.
//
///////////////////////////////////////////////////////////////////////////////

/*
 * Creates new family tree.
 */
void Angena::on_actionNew_triggered()
{    
    qInfo() << "Creating new tree.";

    // If there is another tree open currently, prompt for save/close.
    if (m.isTreeOpen()) Angena::on_actionSave_As_triggered();

    // Show new family tree dialog.

    // Obtain new tree name and other settings.

    // Overwrite model with new open tree state.

    // Clear graphic view.

}

/*
 * Opens existing family tree.
 * Input (dialog): filename - selected file name from file dialog.
 */
void Angena::on_actionOpen_triggered()
{
    qInfo() << "Opening new tree.";

    // If there is another tree open currently, prompt for save/close.
    if (m.isTreeOpen()) Angena::on_actionSave_As_triggered();

    // Browse for tree file.
    QString filename = QFileDialog::getOpenFileName(this, "C://", "GEDCOM (*.txt)");
    qInfo() << filename;
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
    qInfo() << "Saving new tree state.";
    // Only enable if there is a change or undo resolved to original state.
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
    qInfo() << "Saving new tree state as...";
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
    qInfo() << "Closing tree.";
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
    qInfo() << "Opening recent file";
    // Open the tree state, update model tree state.
    // Update display
}

/*
 * Prints current tree state visualization.
 */
void Angena::on_actionPrint_triggered()
{
    qInfo() << "Printing state of tree display.";
    // TODO: Implement printing functionality. Probably another dialog following
    // standard printing functionality such as choose printer, size, layout, etc...
}

/*
 * Terminates Angena application.
 */
void Angena::on_actionExit_triggered()
{
    qInfo() << "Shutting application down.";
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

///////////////////////////////////////////////////////////////////////////////
//
//  Tool button actions
//
///////////////////////////////////////////////////////////////////////////////

/*
 * Reverts to previous tree state before change.
 */
void Angena::on_actionUndo_triggered()
{
    qInfo() << "Undo!";
}

/*
 * Returns tree state to next more recent version. Usually after undone.
 */
void Angena::on_actionRedo_triggered()
{
    qInfo() << "Redo!";
}

/*
 * Adds new person to the current tree state.
 */
void Angena::on_actionAdd_Person_triggered()
{
    qInfo() << "Add!";
    // Add person dialog
    // Retrieve all information
    // Pass to model
}

/*
 * Removes selected person from the current tree state.
 */
void Angena::on_actionRemove_Person_triggered()
{
    qInfo() << "Remove!";
}

/*
 * Edits selected person in the current tree state.
 */
void Angena::on_actionEdit_Person_triggered()
{
    qInfo() << "Edit!";
}

/*
 * Changes graphic view to display tree state in pedigree format.
 */
void Angena::on_actionPedigree_triggered()
{
    qInfo() << "Pedigree!";
    // Referencing model, implement pedigree logic here.
}

/*
 * Changes graphic view to display tree state in hyperbolic format.
 */
void Angena::on_actionHyperbolic_triggered()
{
    qInfo() << "Hyper!";
    // Referencing model, implement hyperbolic logic here.
}

/*
 * Changes graphic view to display tree state in fan format.
 */
void Angena::on_actionFan_triggered()
{
    qInfo() << "Fan!";
    // Referencing model, implement fan logic here.
}

///////////////////////////////////////////////////////////////////////////////
//
//  Internal Actions
//
///////////////////////////////////////////////////////////////////////////////

/*
 * Redraws graphic view to reflect current tree state.
 */
void Angena::redraw_graphics_view()
{
    qInfo() << "Redraw!";
    // Referencing model, pull data and draw each person.
}

/*
 * Clears graphic view to reflect empty tree state.
 */
void Angena::clear_graphics_view()
{
    qInfo() << "Clear!";
    // Clear graphics view.
}
