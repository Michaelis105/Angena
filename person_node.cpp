//============================================================================
// Name        : person_node.cpp
// Author      : Michael Louie
// Description : Node containing a person and the relationships with other
//               people.
//============================================================================
#include "person_node.h"

person_node::person_node(unsigned int newId, bool isDeceased)
{
    id = newId;
    p = new person(isDeceased);
    //off_spr_vec;
    //par_vec;
}

/*
 * Sets person's name.
 */
void person_node::setName(Name* newName)
{
    p->updateName(newName);
}

/*
 * Sets birth address.
 */
void person_node::setBirthAddr(Addr* newBAddr)
{
    p->updateBirthAddr(newBAddr);
}

/*
 * Sets death address.
 */
void person_node::setDeathAddr(Addr* newDAddr)
{
    p->updateDeathAddr(newDAddr);
}

/*
 * Sets birth date.
 */
void person_node::setBirthDate(p_Date* newBDate)
{
    p->updateBirthDate(newBDate);
}

/*
 * Sets death date.
 */
void person_node::setDeathDate(p_Date* newDDate)
{
    p->updateDeathDate(newDDate);
}

/*
 * Sets living status.
 */
void person_node::setAliveStatus(bool state)
{
    p->updateAliveStatus(state);
}

/*
 * Sets notes.
 */
void person_node::setNotes(char * newNote)
{
    p->updateNotes(newNote);
}
