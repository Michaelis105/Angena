//================================================
// Name        : angena.cpp
// Author      : Michael Louie
// Description : Controller for primary UI window.
//================================================
#include <QDebug>
#include <string>
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

/**
 * @brief Creates new family tree on click.
 */
void Angena::on_actionNewFamily_triggered()
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

/**
 * @brief Opens existing family tree on click.
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

/**
 * @brief Commits family tree state to an existing/opened file on click.
 */
void Angena::on_actionSave_triggered()
{
    // If a file does not exist or never registered, call save_as() and retrieve a file name/path
    // Else
    // Save tree state to file path.
    // Update save status bar.
}

/**
 * @brief Saves family tree state to a new file on click.
 *        Displays dialog to determine save file path in GEDCOM format to disk.
 *        Also called by other functions.
 */
void Angena::on_actionSave_As_triggered()
{
    qDebug() << "Saving new tree state as...";
    // TODO: Dialog box.
    // TODO: Call the writer to generate GEDCOM based on family tree state.
}

/**
 * @brief Closes currently opened family tree on click.
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

/**
 * @brief Prints current tree state visualization on click.
 */
void Angena::on_actionPrint_triggered()
{
    qDebug() << "Printing state of tree display.";
    // TODO: Implement printing functionality. Probably another dialog following
    // standard printing functionality such as choose printer, size, layout, etc...
}

/**
 * @brief Terminates Angena application on click.
 */
void Angena::on_actionExit_triggered()
{
    qDebug() << "Shutting application down.";
    // TODO: Prompt save if tree state has changed.
    // TODO: Destroy stuff as needed.
    close();

}


/**
 * @brief Displays dialog containing simple version,
 *        repository, and legal information pertaining
 *        to Angena on click.
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

/**
 * @brief Reverts to previous tree state before change on click.
 */
void Angena::on_actionUndo_triggered()
{
    qDebug() << "Undo!";
    // NOTE: Method not implemented!
}

/**
 * @brief Returns tree state to next more recent version. Usually after undone.
 */
void Angena::on_actionRedo_triggered()
{
    qDebug() << "Redo!";
    // NOTE: Method not implemented!
}

/**
 * @brief Adds new person to the current tree state on click.
 */
void Angena::on_actionAdd_Person_triggered()
{
    qDebug() << "Add!";
    // Add person dialog
    // Retrieve all information
    // Pass to model
}

/**
 * @brief Removes selected person from the current tree state on click.
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

/**
 * @brief Commits all side info entries to selected person on click.
 */
void Angena::on_pushButtonSavePerson_clicked()
{
    vector<string> names = {
        ui->lineEditTitle->text().toStdString(),
        ui->lineEditFirstName->text().toStdString(),
        ui->lineEditMiddleName->text().toStdString(),
        ui->lineEditLastName->text().toStdString(),
        ui->lineEditNickName->text().toStdString(),
        ui->comboBoxSuffix->itemData(ui->comboBoxSuffix->currentIndex()).toString().toStdString()
    };

    string sex = ui->comboBoxSex->itemData(ui->comboBoxSex->currentIndex()).toString().toStdString();

    vector<string> birthDate = {
        to_string(ui->spinBoxBirthMonth->value()),
        to_string(ui->spinBoxBirthDay->value()),
        to_string(ui->spinBoxBirthYear->value())
    };
    vector<string> birthAddr = {
        ui->lineEditBirthAddress->text().toStdString(),
        ui->lineEditBirthStProv->text().toStdString(),
        ui->lineEditBirthCity->text().toStdString(),
        ui->lineEditBirthCountry->text().toStdString(),
        ui->lineEditBirthZipCode->text().toStdString()
    };

    string nt = ui->plainTextEditNotes->toPlainText().toStdString();

    vector<string> deathDate = {
        to_string(ui->spinBoxDeathMonth->value()),
        to_string(ui->spinBoxDeathDay->value()),
        to_string(ui->spinBoxDeathYear->value())
    };
    vector<string> deathAddr = {
        ui->lineEditDeathAddress->text().toStdString(),
        ui->lineEditDeathStProv->text().toStdString(),
        ui->lineEditDeathCity->text().toStdString(),
        ui->lineEditDeathCountry->text().toStdString(),
        ui->lineEditDeathZipCode->text().toStdString()
    };

    bool alive = ui->radioButtonAlive->isChecked();
    bool deadunk = ui->radioButtonDeadUnk->isChecked();
    bool living = true; // Default to true for now
    if (alive == deadunk) {
        qDebug() << "UI Error: Person cannot be both alive and dead/unknown!";
    } else if (!alive && deadunk) {
        living = false;
    } else if (alive && !deadunk) {
        living = true;
    } else {
        qDebug() << "UI Error: Error identifying living state!";
    }

    m.editPerson(names, sex, birthDate, birthAddr, nt, deathDate, deathAddr, living);
}

// TODO: Method to update all widgets after new person is selected.

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


