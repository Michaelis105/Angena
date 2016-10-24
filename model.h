//============================================================================
// Name        : model.h
// Author      : Michael Louie
// Description : Header for the Angena model.
//============================================================================
#ifndef MODEL_H
#define MODEL_H

// The model contains a family tree to operate on when a UI event occurs.
#include "familytree.h"

class model
{
    private:
        person_node * curSelPerson;
        familytree curft;

    public:
        model();
        bool addPerson();
        bool delPerson();
        bool editPerson();
        bool connectPerson();
        bool disconnectPerson();

};

#endif // MODEL_H
