//============================================================================
// Name        : model.cpp
// Author      : Michael Louie
// Description : Model containing logic for operating on family tree object.
//============================================================================
#include "model.h"

model::model() {
    person_node * curSelPerson = nullptr;
    person_node * clipboard;
    familytree curft;
    //std::deque<> history;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Family tree functions
//
///////////////////////////////////////////////////////////////////////////////

/*
 * Adds a new person to the family tree.
 */
bool model::addPerson() {
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
bool model::delPerson() {
    return false;
}

/*
 * Changes the information pertaining to a specific person..
 * Input: person -
 *        field  -
 *        data   -
 */
bool model::editPerson() {
    return false;
}

/*
 * Connects a relationship between two persons.
 * Input: person1, person2
 */
bool model::connectPerson() {
    // If there is already a relationship between two persons, do nothing or throw error?
    return false;
}

/*
 * Disconnects the relationship between two persons.
 * Input: person1, person2
 */
bool model::disconnectPerson() {
    return false;
}

/*
 * Clears the stored tree state.
 */
void model::clearTreeState() {

}

/*
 * Opens a tree state (from an existing file).
 */
void model::openTreeState() {

}

/*
 * Commits the stored tree state to a file.
 */
void model::saveTreeState() {

}


///////////////////////////////////////////////////////////////////////////////
//
//  Clipboard functions
//
///////////////////////////////////////////////////////////////////////////////

/*
 * Reverts tree state to a previous version based on a previous stored user's action.
 */
void model::undo() {

}

/*
 * Reverts tree state to a newest version based on an undone stored user's action.
 */
void model::redo() {

}




