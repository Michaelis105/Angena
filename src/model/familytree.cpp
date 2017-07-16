//=================================================
// Name        : familyTree.cpp
// Author      : Michael Louie
// Description : Model for a family tree structure
//=================================================
#include "familytree.h"

FamilyTree::FamilyTree()
{
    /* Track maximum 65535 individuals covering enough generations
     * dating back to around the 1600s. */
    unsigned int totalPersonNodes = 0;
    // Store all persons in some data structure, maybe hash table?
}

/**
 * @brief Gets total number of person nodes counted in family tree
 * @return 0-65535
 */
unsigned int FamilyTree::getTotalPersonNodes() {
    return totalPersonNodes;
}

/*
 * Adds a new person to the family tree.
 */
void FamilyTree::addPerson(unsigned int newId) {
    PersonNode * newP = new PersonNode(newId);
    // Record person.
    totalPersonNodes++;
}

/*
 * Removes a specific person from the family tree.
 * Disconnects the relationship between person and others
 * as necessary.
 * Input: person
 */
void FamilyTree::delPerson(PersonNode * p) {
    // Delete person.
    totalPersonNodes--;
}

/*
 * Changes the information pertaining to a specific person..
 * Input: person -
 *        field  -
 *        data   -
 */
void editPerson(PersonNode * p, vector<string> fieldValues) {
    // Process fieldValues? Or do it in model?
}

/**
 * @brief Connects a parent and child node such that child is parent's offspring
 *        and child's parent is parent.
 * @param parent
 * @param child
 */
void FamilyTree::connectPersons(PersonNode * parent, PersonNode * child) {
    if (parent != nullptr && child != nullptr) {
        // TODO: Check for existing connection?
        if (!parent->template getSex<string*>()->compare("MALE")) {
            child->setFather(parent);
        } else {
            child->setMother(parent);
        }
        parent->addOffspring(child);
    } else {
        throw invalid_argument( "FamilyTree::connectPersons(): Either parent or child was null." );
    }
}

/**
 * @brief Disconnects a parent and child node such that child is no longer
 *        parent's offspring and child's parent is not parent.
 * @param parent
 * @param child
 */
void FamilyTree::disconnectPersons(PersonNode * parent, PersonNode * child) {
    // TODO: Check if there is no connection?
    if (parent != nullptr && child != nullptr) {
        if (!parent->template getSex<string*>()->compare("MALE")) {
            child->setFather(parent);
        } else {
            child->setMother(parent);
        }
        parent->removeOffspring(child);
    } else {
        throw invalid_argument( "FamilyTree::disconnectPersons(): Either parent or child was null." );
    }
}
