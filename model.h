//============================================================================
// Name        : model.h
// Author      : Michael Louie
// Description : Header for the Angena model.
//============================================================================
#ifndef MODEL_H
#define MODEL_H

// The model contains a family tree to operate on when a UI event occurs.
#include "familytree.h"
#include "file_io.h"
#include <deque>

class model
{
    private:
        person_node * curSelPerson;
        person_node * clipboard;
        familytree curft;
        //std::deque<> history;
        file_io fio;

    public:
        model();
        bool addPerson();
        bool delPerson();
        bool editPerson();
        bool connectPerson();
        bool disconnectPerson();
        void undo();
        void redo();
        void clearTreeState();
        void openTreeState();
        void saveTreeState();
        bool isTreeOpen();

        Name serializeName();
        Addr serializeBirthAddr();
        p_Date serializeBirthDate();
        Addr serializeDeathAddr();
        p_Date serializeDeathDate();

};

#endif // MODEL_H
