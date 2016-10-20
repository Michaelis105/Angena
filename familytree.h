//============================================================================
// Name        : familytree.h
// Author      : Michael Louie
// Description : Header for the family tree.
//============================================================================

#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include "person.h"

class familytree
{
    private:
        int numberPerson;
        person *curSelPerson;
        person * persons[];
    public:
        familytree();
};

#endif // FAMILYTREE_H
