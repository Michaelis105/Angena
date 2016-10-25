//============================================================================
// Name        : model.cpp
// Author      : Michael Louie
// Description : Model containing logic for operating on family tree object.
//============================================================================
#include "model.h"
#include "familytree.h"
model::model() {
    person_node * curSelPerson = nullptr;
    familytree curft;
    std::deque<person_node> clipboard;
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
 * Connect a relationship between two persons.
 * Input: person -
 *        field  -
 *        data   -
 */
bool model::editPerson() {
    return false;
}

/*
 * Connect a relationship between two persons.
 * Input: person1, person2
 */
bool model::connectPerson() {
    // If there is already a relationship between two persons, do nothing or throw error?
    return false;
}

/*
 * Disconnect the relationship between two persons.
 * Input: person1, person2
 */
bool model::disconnectPerson() {
    return false;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Clipboard functions
//
///////////////////////////////////////////////////////////////////////////////


