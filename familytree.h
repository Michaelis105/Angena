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
        void addPerson(unsigned int newId, bool isDeceased);
        void delPerson();
        void editPerson();
        void connectPerson();
        void disconnectPerson();
};

#endif // FAMILYTREE_H
