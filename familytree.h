//============================================================================
// Name        : familytree.h
// Author      : Michael Louie
// Description : Header for the family tree.
//============================================================================
#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include "person_node.h"

class familytree
{
    private:
        int numberPerson;
        person_node * persons[];
    public:
        familytree();
        bool addPerson();
        bool delPerson();
        bool editPerson();
        bool connectPerson();
        bool disconnectPerson();
};

#endif // FAMILYTREE_H
