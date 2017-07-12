//==========================================
// Name        : familytree.h
// Author      : Michael Louie
// Description : Header for the family tree.
//==========================================
#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include "personNode.h"

class FamilyTree
{
    private:
        int numberPerson;
        PersonNode * persons[];
    public:
        FamilyTree();
        void addPerson(unsigned int newId, bool isDeceased);
        void delPerson();
        void editPerson();
        void connectPerson();
        void disconnectPerson();
};

#endif // FAMILYTREE_H
