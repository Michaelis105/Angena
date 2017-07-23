//==========================================================================
// Name        : model.cpp
// Author      : Michael Louie
// Description : Model containing logic for operating on family tree object.
//==========================================================================
#include "model.h"

struct PersonDetails {
    vector<string> names;
    string sex;
    vector<string> birthDate;
    vector<string> birthAddr;
    string notes;
    vector<string> deathDate;
    vector<string> deathAddr;
    bool living;
} tempStore;

Model::Model() {
    FamilyTree * curft;
    FileIO fio;
    PersonNode * curSelPerson = nullptr;
    //personNode * clipboard = nullptr;
    //std::deque<> history;
}

/////////////////////////
//
//  Family tree functions
//
/////////////////////////

bool Model::isChanged() {
    return hasChanged;
}

/**
 * @brief Initializes new family tree.
 * @pre Any previous family tree state must have already
 *      been deallocated
 * @post A blank family tree state
 */
void Model::initializeNewFamilyTree() {
    curft = new FamilyTree();
}

/**
 * @brief Adds a 'blank' person to family tree.
 */
void Model::addPerson() {
    QUuid newId = QUuid::createUuid();
    curft->addPerson(newId.toString().toStdString());
    hasChanged = true;
}

/*
 * Removes a specific person from the family tree.
 * Disconnects the relationship between person and others
 * as necessary.
 * Input: person
 */
void Model::delPerson() {
    // TODO: How should person be identified by view? PersonNode? ID?
    hasChanged = true;
}

/*
 * Changes the information pertaining to a specific person..
 * Input: person -
 *        field  -
 *        data   -
 */
void Model::editPerson(vector<string> names, string sex,
                       vector<string> birthDate, vector<string> birthAddr,
                       string notes, vector<string> deathDate,
                       vector<string> deathAddr, bool living) {
    if (curSelPerson) {
        curSelPerson->template setNames<vector<string>>(names);
        curSelPerson->template setSex<string>(sex);
        curSelPerson->template setBirthAddr<vector<string>>(birthAddr);
        curSelPerson->template setBirthDate<vector<string>>(birthDate);
        curSelPerson->template setDeathAddr<vector<string>>(deathAddr);
        curSelPerson->template setDeathDate<vector<string>>(deathDate);
        if (living) {
            curSelPerson->template setLivingStatus<string>("Alive");
        } else {
            curSelPerson->template setLivingStatus<string>("Deceased/Unknown");
        }
        curSelPerson->template setNotes<string>(notes);
    } else {
        throw runtime_error( "Model::editPerson: No current selected person to edit, we shouldn't be here!" );
    }
    hasChanged = true;
}

/*
 * Connects a relationship between two persons.
 * Input: person1, person2
 */
void Model::connectPerson() {
    // If there is already a relationship between two persons, do nothing or throw error?
    hasChanged = true;
}

/*
 * Disconnects the relationship between two persons.
 * Input: person1, person2
 */
void Model::disconnectPerson() {
    hasChanged = true;
}

/*
 * Clears the stored tree state.
 */
void Model::clearTreeState() {
    //curft = 0;
}

/*
 * Checks if there is an existing tree state open or not.
 * @return true if open, false if not open/null.
 */
bool Model::isTreeOpen() {
    return (curft != nullptr);
    //if (!curft) return false;
    //else return true;
}

/**
 * @brief Checks if there is a currently selected person.
 */
PersonNode* Model::getCurSelPerson() {
    return curSelPerson;
}

/**
 * @brief Cleans up all allocations in environment in
 *      event of application shutdown.
 */
void Model::cleanUp() {
    delete curft;
    // End fileio streams
    curSelPerson = nullptr;
}

/**
 * @brief Updates temp store with new person details.
 * @pre A person is selected
 * @post Store is updated
 */
void Model::updatePersonTempStore() {
    if (curSelPerson != nullptr) {
        //curSelPerson->getNames();

    } else {
        throw runtime_error("Model::updatePersonTempStore(): "
                            "Cannot update temp storage with "
                            "null current selected person!");
    }
}

/////////////////////
//
//  File IO functions
//
/////////////////////

/**
 * @brief Opens tree state (from an existing file).
 * @param filename Compatible file
 */
void Model::openTreeState(string filename) {

}

/**
 * @brief Commits the stored tree state to a file.
 */
void Model::saveTreeState() {

}

/**
 * @brief Commits the stored tree state to a file
 *        specified as filename.
 */
void Model::saveTreeState(string filename) {

}

/**
 * @brief Checks if File IO has a filename
 *        associated with family tree state.
 * @return true if has, false otherwise
 */
bool Model::hasFilename() {
    return false;
    // TODO: Implement
}

///////////////////////
//
//  Clipboard functions
//
///////////////////////

/*
 * Reverts tree state to a previous version based on a previous stored user's action.
 */
void Model::undo() {
    // NOTE: Method not implemented!
}

/*
 * Reverts tree state to a newest version based on an undone stored user's action.
 */
void Model::redo() {
    // NOTE: Method not implemented!
}
