//============================================================================
// Name        : model.h
// Author      : Michael Louie
// Description : Header for the Angena model.
//============================================================================
#ifndef MODEL_H
#define MODEL_H

// The model contains a family tree to operate on when a UI event occurs.
#include "familytree.h"
#include "writer.h"
#include "reader.h"
#include <deque>

class model
{
    private:
        person_node * curSelPerson;
        person_node * clipboard;
        familytree curft;
        //std::deque<> history;
        reader r;
        writer w;

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

};

#endif // MODEL_H
