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
        void setName(Name* newName);
        void setBirthAddr(Addr* newBAddr);
        void setDeathAddr(Addr* newDAddr);
        void setBirthDate(p_Date* newBDate);
        void setDeathDate(p_Date* newDDate);
        void setAliveStatus(bool state);
        void setNotes(char * newNote);
};

#endif // PERSON_NODE_H
