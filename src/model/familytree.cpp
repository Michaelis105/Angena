//=================================================
// Name        : familyTree.cpp
// Author      : Michael Louie
// Description : Model for a family tree structure.
//=================================================
#include "familyTree.h"

// there is a root person/couple of a family tree. Each person/pair can have any number of children.
FamilyTree::FamilyTree()
{
    int numberPerson = 0;
    //person_node * persons[] = nullptr; // use malloc instead.
}

/*
 * Adds a new person to the family tree.
 */
void FamilyTree::addPerson(unsigned int newId, bool isDeceased) {
    PersonNode * newP = new PersonNode(newId);
    //if (newP == nullptr) return false;
    numberPerson++;
}

/*
 * Removes a specific person from the family tree.
 * Disconnects the relationship between person and others
 * as necessary.
 * Input: person
 */
void FamilyTree::delPerson() {
    // get id or person?
    numberPerson--;
}

/*
 * Changes the information pertaining to a specific person..
 * Input: person -
 *        field  -
 *        data   -
 */
void FamilyTree::editPerson() {
    // get id or person?
}

/*
 * Connects a relationship between two persons.
 * Input: person1, person2
 */
void FamilyTree::connectPerson() {
    // get id or person?
    // If there is already a relationship between two persons, do nothing or throw error?
}

/*
 * Disconnects the relationship between two persons.
 * Input: person1, person2
 */
void FamilyTree::disconnectPerson() {
    // get id or person?
}
