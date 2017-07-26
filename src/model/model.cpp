//==========================================================================
// Name        : model.cpp
// Author      : Michael Louie
// Description : Model containing logic for operating on family tree object.
//==========================================================================
#include "model.h"

Model::Model() {
    FamilyTree * curft = nullptr;
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

/**
 * @brief Changes the information pertaining to a specific person.
 * @param Serialized by view to be forwarded to selected person.
 *        See respective classes for vector-element ordering
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
        curSelPerson->template setLivingStatus<string>((living)? "Alive" : "Deceased/Unknown");
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
        ts.names = serializeName(curSelPerson->getNames<PersonName*>());
        ts.sex = *(curSelPerson->getSex<string*>());
        ts.birthDate = serializeDate(curSelPerson->getBirthDate<Date*>());
        ts.birthAddr = serializeAddress(curSelPerson->getBirthAddr<PersonAddress*>());
        ts.deathDate = serializeDate(curSelPerson->getDeathDate<Date*>());
        ts.deathAddr = serializeAddress(curSelPerson->getDeathAddr<PersonAddress*>());
        ts.notes = *(curSelPerson->getNotes<string*>());
        ts.living = (*(curSelPerson->getLivingStatus<string*>()) == "Alive") ? true : false;
    } else {
        throw runtime_error("Model::updatePersonTempStore(): "
                            "Cannot update temp storage with "
                            "null current selected person!");
    }
}

/**
 * @brief Converts person name parts to string vector
 * @param name PersonName
 * @return string vector
 */
vector<string> Model::serializeName(PersonName* name) {
    vector<string> n = {
        name->getTitle(),
        name->getFirstName(),
        name->getMiddleName(),
        name->getLastName(),
        name->getNickName(),
        name->getSuffix()
    };
    return n;
}

/**
 * @brief Converts person date parts to string vector
 * @param name Date
 * @return string vector
 */
vector<int> Model::serializeDate(Date* date) {
    vector<int> d = {
        date->getMonth(),
        date->getDay(),
        date->getYear()
    };
    return d;
}

/**
 * @brief Converts person date parts to string vector
 * @param name Date
 * @return string vector
 */
vector<string> Model::serializeAddress(PersonAddress* addr) {
    vector<string> a = {
        addr->getHomeAddr(),
        addr->getStateProv(),
        addr->getCity(),
        addr->getCountry(),
        addr->getZipCode()
    };
    return a;
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
