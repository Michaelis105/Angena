//==========================================
// Name        : familytree.h
// Author      : Michael Louie
// Description : Header for the family tree
//==========================================
#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include <stdexcept>
#include <vector>

#include "personnode.h"

class FamilyTree
{
    private:
        //PersonNode * persons[];
    protected:
        unsigned int totalPersonNodes;
    public:
        FamilyTree();
        unsigned int getTotalPersonNodes();
        void addPerson(unsigned int newId);
        void delPerson(PersonNode * p);
        void editPerson(PersonNode * p, vector<string> fieldValues);
        void connectPersons(PersonNode * parent, PersonNode * child);
        void disconnectPersons(PersonNode * parent, PersonNode * child);
};

#endif // FAMILYTREE_H
