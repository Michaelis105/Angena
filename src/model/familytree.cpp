//=================================================
// Name        : familyTree.cpp
// Author      : Michael Louie
// Description : Model for a family tree structure
//=================================================
#include "familytree.h"

typedef std::unordered_map<unsigned int, PersonNode*>::const_iterator umIter;
typedef std::pair<unsigned int, PersonNode*> idpnPair;

FamilyTree::FamilyTree() { }

/**
 * @brief Gets total number of person nodes counted in family tree
 * @return 0-65535
 */
unsigned int FamilyTree::getTotalPersonNodes() {
    return people.size();
}

/**
 * @brief Adds 'blank' person to family tree.
 * @param newId unique identifier for person node
 */
void FamilyTree::addPerson(unsigned int newId) {
    PersonNode * newPer = new PersonNode(newId);
    idpnPair newPair (newId, newPer);
    people.insert(newPair);
}

/**
 * @brief Removes specific person from family tree.
 * @param id unique identifier for person node
 */
void FamilyTree::delPerson(unsigned int id) {
    umIter finding = people.find(id);
    if (finding == people.end()) {
        throw runtime_error("FamilyTree::delPerson(): Person to delete not found!");
    } else {
        people.erase(finding);
        delete finding->second; // Delete person node from model.
    }
}

/**
 * @brief Finds specific person in family tree.
 * @param id unique identifier for person node
 * @return PersonNode pointer if exists, nullptr otherwise
 */
PersonNode * FamilyTree::findPerson(unsigned int id) {
    umIter finding = people.find(id);
    if (finding == people.end()) {
        return nullptr;
    } else {
        return finding->second;
    }
}

/*
 * Changes the information pertaining to a specific person..
 * Input: person -
 *        field  -
 *        data   -
 */
void FamilyTree::editPerson(PersonNode * p, vector<string> fieldValues) {
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
