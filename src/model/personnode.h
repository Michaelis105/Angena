//===============================================================
// Name        : personNode.h
// Author      : Michael Louie
// Description : Header for a node containing a person data unit.
//================================-==============================
#ifndef PERSONNODE_H
#define PERSONNODE_H

#include "person.h"
#include <vector>
typedef std::vector<Person> PVec;
class PersonNode
{
    private:
        unsigned int id; // 0-65535;
        Person* p;
        PVec off_spr_vec;
        PVec par_vec;
    public:
        PersonNode(unsigned int newId);
        template <class nameType>
        void setName(nameType* newName);
        template <class addrType>
        void setBirthAddr(addrType* newBAddr);
        template <class addrType>
        void setDeathAddr(addrType* newDAddr);
        template <class dateType>
        void setBirthDate(dateType* newBDate);
        template <class dateType>
        void setDeathDate(dateType* newDDate);
        template <class livingStateType>
        void setAliveStatus(livingStateType* state);
        template <class noteType>
        void setNotes(noteType* newNote);
        ~PersonNode();
};

#endif // PERSONNODE_H
