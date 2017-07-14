//===============================================================
// Name        : personNode.h
// Author      : Michael Louie
// Description : Header for a node containing a person data unit
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
        Person ** mother;
        Person ** father;
        Person ** partner;
    public:
        PersonNode(unsigned int newId);
        PersonNode(unsigned int newId, Person * f, Person * m);
        ~PersonNode();
        template <class nameType>
        void setNames(nameType* newName);
        template <class addrType>
        void setBirthAddr(addrType* newBAddr);
        template <class addrType>
        void setDeathAddr(addrType* newDAddr);
        template <class dateType>
        void setBirthDate(dateType* newBDate);
        template <class dateType>
        void setDeathDate(dateType* newDDate);
        template <class livingStateType>
        void setLivingStatus(livingStateType* state);
        template <class noteType>
        void setNotes(noteType* newNote);

        template <class nameType>
        nameType getNames();
        template <class addrType>
        addrType getBirthAddr();
        template <class addrType>
        addrType getDeathAddr();
        template <class dateType>
        dateType getBirthDate();
        template <class dateType>
        dateType getDeathDate();
        template <class livingStateType>
        livingStateType getLivingStatus();
        template <class noteType>
        noteType getNotes();
};

#endif // PERSONNODE_H
