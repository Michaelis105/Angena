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
 * @brief Processes save confirmation dialog action
 * @post Respective action from confirmation dialog is processed.
 * @return true if continue with parent caller action, false to discontinue
 */
bool Angena::processSaveConfirmationDialog() {
    switch (d.dsc.getSaveAction()) {
        case -1: break; // No option selected, default to action
        case 0: on_actionSave_triggered();
                break;
        case 1: on_actionSave_As_triggered();
                break;
        case 3: return false; // Cancelled, discontinue action.
        case 2: break; // Do not save, no action, parent caller continues.
        default: qDebug() << "Angena::processSaveConfirmationDialog(): Could not determine save action!";
        // Defaults to parent caller action
    }
    return true;
}

/**
 * @brief Creates new family tree on click.
 */
void Angena::on_actionNewFamily_triggered()
{
    qDebug() << "Creating new tree.";
    if (m.isTreeOpen() && m.isChanged()) {
        d.showSaveConfirmationDialog();
    }
    if (processSaveConfirmationDialog()) {
        m.cleanUp();
        m.initializeNewFamilyTree();
        clearGraphicsView();
    }
}

/**
 * @brief Opens existing family tree on click.
 */
void Angena::on_actionOpen_triggered()
{
    qDebug() << "Opening new tree.";
    if (m.isTreeOpen() && m.isChanged()) {
        d.showSaveConfirmationDialog();
    }
    if (processSaveConfirmationDialog()) {
        QString filename = QFileDialog::getOpenFileName(this, "C://", "GEDCOM (*.txt)");
        qDebug() << filename;
        if (filename != NULL && filename.size() > 0) {
            m.cleanUp();
            clearGraphicsView();
            m.initializeNewFamilyTree();
            m.openTreeState(filename.toStdString());
            redrawGraphicsView();
        }
    }
}

/**
 * @brief Commits family tree state to an existing/opened file on click.
 */
void Angena::on_actionSave_triggered()
{
    qDebug() << "Saving new tree state...";
    if (!m.hasFilename()) {
        on_actionSave_As_triggered();
    } else {
        m.saveTreeState();
    }
}

/**
 * @brief Saves family tree state to a new file on click.
 *        Displays dialog to determine save file path in GEDCOM format to disk.
 *        Also called by other functions.
 */
void Angena::on_actionSave_As_triggered()
{
    qDebug() << "Saving as new tree state...";
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Family Tree"),
                                                    "", tr("Angena Family Tree (*.aft);;All Files (*)"));
    if (filename != NULL && filename.size() > 0) {
        m.saveTreeState(filename.toStdString());
    }
}

/**
 * @brief Closes currently opened family tree on click.
 */
void Angena::on_actionClose_triggered()
{
    qDebug() << "Closing tree.";
    if (m.isTreeOpen() && m.isChanged()) {
        d.showSaveConfirmationDialog();
    }
    if (processSaveConfirmationDialog()) {
        m.cleanUp();
        clearGraphicsView();
    }
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
    if (m.isTreeOpen() && m.isChanged()) {
        d.showSaveConfirmationDialog();
    }
    if (processSaveConfirmationDialog()) {
        m.cleanUp();
        clearGraphicsView(); // NOTE: Is clearing view necessary if closing application?
        close();
    }
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
    if (m.isTreeOpen()) {
        m.addPerson();
        redrawGraphicsView();
    } else {
        throw runtime_error("Angena::on_actionAdd_Person_triggered(): Cannot add person if family tree isn't open!");
    }
}

/**
 * @brief Removes selected person from the current tree state on click.
 */
void Angena::on_actionRemove_Person_triggered()
{
    qDebug() << "Remove!";
    if (!m.isTreeOpen()) {
        throw runtime_error("Angena::on_actionRemove_Person_triggered(): Cannot remove person if family tree isn't open!");
    } else if (m.getCurSelPerson() == nullptr) {
        throw runtime_error("Angena::on_actionRemove_Person_triggered(): Cannot remove person if not selected!");
    } else {
        m.delPerson();
    }
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

/**
 * @brief Updates information panel with person's details.
 * @post Side info panel fields contain person's details
 */
void Angena::updatePersonDetails() {
    m.updatePersonTempStore();
    // TODO: Implement
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


