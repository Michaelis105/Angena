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

void person_node::updateName(Name* newName)
{
    p->updateName(newName);
}

void person_node::updateBirthAddr(Addr* newBAddr)
{
    p->updateBirthAddr(newBAddr);
}

void person_node::updateDeathAddr(Addr* newDAddr)
{
    p->updateDeathAddr(newDAddr);
}

void person_node::updateBirthDate(p_Date* newBDate)
{
    p->updateBirthDate(newBDate);
}

void person_node::updateDeathDate(p_Date* newDDate)
{
    p->updateDeathDate(newDDate);
}

void person_node::updateAliveStatus(bool state)
{
    p->updateAliveStatus(state);
}

void person_node::updateNotes(char * newNote)
{
    p->updateNotes(newNote);
}
