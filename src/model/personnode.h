//===============================================================
// Name        : personNode.h
// Author      : Michael Louie
// Description : Header for a node containing a person data unit.
//================================-==============================
#ifndef PERSONNODE_H
#define PERSONNODE_H
#include "person.h"
#include <vector>

class PersonNode
{
    private:
        unsigned int id;
        Person * p;
    public:
        PersonNode(unsigned int newId);
        ~PersonNode();
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
};

#endif // PERSONNODE_H
