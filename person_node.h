//============================================================================
// Name        : person_node.h
// Author      : Michael Louie
// Description : Header for a node containing a person data unit.
//============================================================================
#ifndef PERSON_NODE_H
#define PERSON_NODE_H

#include "person.h"
#include <vector>
typedef std::vector<person> p_vec;
class person_node
{
    private:
        unsigned int id; // 0-65535;
        person* p;
        p_vec off_spr_vec;
        p_vec par_vec;
    public:
        person_node(unsigned int newId, bool isDeceased);
        void updateName(Name* newName);
        void updateBirthAddr(Addr* newBAddr);
        void updateDeathAddr(Addr* newDAddr);
        void updateBirthDate(p_Date* newBDate);
        void updateDeathDate(p_Date* newDDate);
        void updateAliveStatus(bool state);
        void updateNotes(char * newNote);
};

#endif // PERSON_NODE_H
