//==========================================
// Name        : familytree.h
// Author      : Michael Louie
// Description : Header for the family tree
//==========================================
#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include <stdexcept>
#include <unordered_map>
#include <vector>

#include "personnode.h"

class FamilyTree
{
    private:
        std::unordered_map<unsigned int, PersonNode*> people;
        unsigned int totalPersonNodes;
    public:
        FamilyTree();
        unsigned int getTotalPersonNodes();
        void addPerson(unsigned int newId);
        void delPerson(unsigned int id);
        void editPerson(PersonNode * p, vector<string> fieldValues);
        PersonNode * findPerson(unsigned int id);
        void connectPersons(PersonNode * parent, PersonNode * child);
        void disconnectPersons(PersonNode * parent, PersonNode * child);
};

#endif // FAMILYTREE_H
