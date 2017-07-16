//========================================================================
// Name        : personNode.cpp
// Author      : Michael Louie
// Description : Node containing a person and relationships with other
//               people.
//========================================================================
#include "personnode.h"

PersonNode::PersonNode(unsigned int newId)
{
    id = newId;
    p = new Person();
    father = nullptr;
    mother = nullptr;
}

// TODO: Handle what to do with other people attributes.
PersonNode::PersonNode(unsigned int newId, PersonNode * f, PersonNode * m)
{
    id = newId;
    p = new Person();
    father = f;
    mother = m;
}

PersonNode::~PersonNode() {
    delete p;
    // remove pointers to this person node.
}

// NOTE: See personnode.h for template method declarations and body.

/**
 * @brief Set person node's father.
 * @param f father node.
 */
void PersonNode::setFather(PersonNode * f) {
    father = f;
}

/**
 * @brief Set person node's mother.
 * @param m mother node
 */
void PersonNode::setMother(PersonNode * m) {
    mother = m;
}

/**
 * @brief Gets person node's father.
 * @return PersonNode if set, null if no known father
 */
PersonNode* PersonNode::getFather() {
    return father;
}

/**
 * @brief Gets person node's mother.
 * @return PersonNode if set, null if no known father
 */
PersonNode* PersonNode::getMother() {
    return mother;
}

/**
 * @brief Connects person (parent) and offspring.
 * @param os offspring to connect
 */
void PersonNode::addOffspring(PersonNode * os) {
    if (os != nullptr) {
        offspring.push_back(os);
    } else {
        throw invalid_argument( "PersonNode::addOffspring(): Offspring was null." );
    }
}

/**
 * @brief Disconnects person and offspring.
 * @param os offspring to disconnect
 */
void PersonNode::removeOffspring(PersonNode * os) {
    if (os != nullptr) {
        if (!offspring.empty()) {
            for (int i = 0; i < offspring.size()-1; i++) {
                if (os == (offspring.at(i))) {
                    offspring.erase(offspring.begin()+i);
                    return;
                }
            }
            throw logic_error( "PersonNode::removeOffspring(): Failed to find offspring to remove." );
        } else {
            throw invalid_argument( "PersonNode::removeOffspring(): Attempt remove offspring when empty." );
        }
    } else {
        throw invalid_argument( "PersonNode::removeOffspring(): Offspring was null." );
    }
}
