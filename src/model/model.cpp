//==========================================================================
// Name        : model.cpp
// Author      : Michael Louie
// Description : Model containing logic for operating on family tree object.
//==========================================================================
#include "model.h"

Model::Model() {
    PersonNode * curSelPerson = nullptr;
    //personNode * clipboard = nullptr;
    FamilyTree * curft;
    FileIO fio;
    //std::deque<> history;
}

Model::~Model() {
    // Do we need a destructor for model?
}

/////////////////////////
//
//  Family tree functions
//
/////////////////////////

/*
 * Adds a new person to the family tree.
 */
bool Model::addPerson() {
    // Create new person object.
    // ...
    return false;
}

/*
 * Removes a specific person from the family tree.
 * Disconnects the relationship between person and others
 * as necessary.
 * Input: person
 */
bool Model::delPerson() {
    return false;
}

/*
 * Changes the information pertaining to a specific person..
 * Input: person -
 *        field  -
 *        data   -
 */
bool Model::editPerson() {
    return false;
}

/*
 * Connects a relationship between two persons.
 * Input: person1, person2
 */
bool Model::connectPerson() {
    // If there is already a relationship between two persons, do nothing or throw error?
    return false;
}

/*
 * Disconnects the relationship between two persons.
 * Input: person1, person2
 */
bool Model::disconnectPerson() {
    return false;
}

/*
 * Clears the stored tree state.
 */
void Model::clearTreeState() {
    //curft = 0;
}

/*
 * Opens a tree state (from an existing file).
 */
void Model::openTreeState() {

}

/*
 * Commits the stored tree state to a file.
 */
void Model::saveTreeState() {

}

/*
 * Checks if there is an existing tree state open or not.
 * @return true if open, false if not open/null.
 */
bool Model::isTreeOpen() {
    return (curft != NULL);
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




