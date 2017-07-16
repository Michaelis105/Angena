//==========================================================================
// Name        : model.cpp
// Author      : Michael Louie
// Description : Model containing logic for operating on family tree object.
//==========================================================================
#include "model.h"

Model::Model() {
    FamilyTree curft;
    FileIO fio;
    //PersonNode * curSelPerson = nullptr;
    //personNode * clipboard = nullptr;
    //std::deque<> history;
}

Model::~Model() {
    // Delete all people, nodes, and data.
    // Close all streams.
}

/////////////////////////
//
//  Family tree functions
//
/////////////////////////

/**
 * @brief Adds a 'blank' person to family tree.
 */
void Model::addPerson() {
    QUuid newId = QUuid::createUuid();
    curft.addPerson(newId.toString().toStdString());
}

/*
 * Removes a specific person from the family tree.
 * Disconnects the relationship between person and others
 * as necessary.
 * Input: person
 */
void Model::delPerson() {
}

/*
 * Changes the information pertaining to a specific person..
 * Input: person -
 *        field  -
 *        data   -
 */
void Model::editPerson() {
}

/*
 * Connects a relationship between two persons.
 * Input: person1, person2
 */
void Model::connectPerson() {
    // If there is already a relationship between two persons, do nothing or throw error?
}

/*
 * Disconnects the relationship between two persons.
 * Input: person1, person2
 */
void Model::disconnectPerson() {
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
    return false;
    //return (curft != NULL);
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
