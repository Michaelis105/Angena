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
    *father = f;
    *mother = m;
}

PersonNode::~PersonNode() {
    delete p;
    delete father;
    delete mother;
}

/*
 * Sets person's name.
 */
template <class nameType>
void PersonNode::setNames(nameType* newName)
{
    p->setNames(newName);
}

/*
 * Sets birth address.
 */
template <class addrType>
void PersonNode::setBirthAddr(addrType* newBAddr)
{
    p->setBirthAddr(newBAddr);
}

/*
 * Sets death address.
 */
template <class addrType>
void PersonNode::setDeathAddr(addrType* newDAddr)
{
    p->setDeathAddr(newDAddr);
}

/*
 * Sets birth date.
 */
template <class dateType>
void PersonNode::setBirthDate(dateType* newBDate)
{
    p->setBirthDate(newBDate);
}

/*
 * Sets death date.
 */
template <class dateType>
void PersonNode::setDeathDate(dateType* newDDate)
{
    p->setDeathDate(newDDate);
}

/*
 * Sets living status.
 */
template <class livingStateType>
void PersonNode::setLivingStatus(livingStateType* state)
{
    p->setLivingStatus(state);
}

/*
 * Sets notes.
 */
template <class noteType>
void PersonNode::setNotes(noteType * newNote)
{
    p->setNotes(newNote);
}

template <class nameType>
nameType PersonNode::getNames() {

}

template <class addrType>
addrType PersonNode::getBirthAddr() {

}

template <class addrType>
addrType PersonNode::getDeathAddr() {

}

template <class dateType>
dateType PersonNode::getBirthDate() {

}

template <class dateType>
dateType PersonNode::getDeathDate() {

}

template <class livingStateType>
livingStateType PersonNode::getLivingStatus() {

}

template <class noteType>
noteType PersonNode::getNotes() {

}
