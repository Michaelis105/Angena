//========================================================================
// Name        : personNode.cpp
// Author      : Michael Louie
// Description : Node containing a person and relationships with other
//               people.
//========================================================================
#include "personNode.h"

PersonNode::PersonNode(unsigned int newId)
{
    id = newId;
    p = new Person();
    father = nullptr;
    mother = nullptr;
}

// TODO: Handle what to do with other people attributes.
PersonNode::PersonNode(unsigned int newId, Person * f, Person * m)
{
    id = newId;
    p = new Person();
    father = f;
    mother = m;
}

PersonNode::~PersonNode() {
    delete p;
    delete father;
    delete mother;
}

/**
 * Sets person's name.
 */
template <class nameType>
void PersonNode::setNames(nameType* newName)
{
    p->setNames(newName);
}

/**
 * Sets person's birth address.
 */
template <class addrType>
void PersonNode::setBirthAddr(addrType* newBAddr)
{
    p->setBirthAddr(newBAddr);
}

/**
 * Sets person's death address.
 */
template <class addrType>
void PersonNode::setDeathAddr(addrType* newDAddr)
{
    p->setDeathAddr(newDAddr);
}

/**
 * Sets person's birth date.
 */
template <class dateType>
void PersonNode::setBirthDate(dateType* newBDate)
{
    p->setBirthDate(newBDate);
}

/**
 * Sets person's death date.
 */
template <class dateType>
void PersonNode::setDeathDate(dateType* newDDate)
{
    p->setDeathDate(newDDate);
}

/**
 * Sets person's living status.
 */
template <class livingStateType>
void PersonNode::setLivingStatus(livingStateType* state)
{
    p->setLivingStatus(state);
}

/**
 * Sets person's notes.
 */
template <class noteType>
void PersonNode::setNotes(noteType * newNote)
{
    p->setNotes(newNote);
}

/**
 * Gets person's name.
 */
template <class nameType>
nameType PersonNode::getNames() {
    return p->getName();
}

/**
 * Gets person's birth address.
 */
template <class addrType>
addrType PersonNode::getBirthAddr() {
    return p->getBirthAddr();
}

/**
 * Gets person's death address.
 */
template <class addrType>
addrType PersonNode::getDeathAddr() {
    return p->getDeathAddr();
}

/**
 * Gets person's birth date.
 */
template <class dateType>
dateType PersonNode::getBirthDate() {
    return p->getBirthDate();
}

/**
 * Gets person's death date.
 */
template <class dateType>
dateType PersonNode::getDeathDate() {
    return p->getDeathDate();
}

/**
 * Gets person's living status.
 */
template <class livingStateType>
livingStateType PersonNode::getLivingStatus() {
    return p->getLivingStatus();
}

/**
 * Gets person's notes.
 */
template <class noteType>
noteType PersonNode::getNotes() {
    return p->getNotes();
}
