//========================================================================
// Name        : personNode.cpp
// Author      : Michael Louie
// Description : Node containing a person and the relationships with other
//               people.
//========================================================================
#include "personNode.h"

PersonNode::PersonNode(unsigned int newId)
{
    id = newId;
    p = new Person();
    //off_spr_vec;
    //par_vec;
}

/*
 * Sets person's name.
 */
template <class nameType>
void PersonNode::setName(nameType* newName)
{
    p->setName(newName);
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
void PersonNode::setAliveStatus(livingStateType* state)
{
    p->setAliveStatus(state);
}

/*
 * Sets notes.
 */
template <class noteType>
void PersonNode::setNotes(noteType * newNote)
{
    p->setNotes(newNote);
}

PersonNode::~PersonNode() {

}
