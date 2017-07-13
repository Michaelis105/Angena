//===========================================
// Name        : model.h
// Author      : Michael Louie
// Description : Header for the Angena model.
//===========================================
#ifndef MODEL_H
#define MODEL_H

// The model contains a family tree to operate on when a UI event occurs.
#include "familyTree.h"
#include "fileIO.h"

class Model
{
    private:
        PersonNode * curSelPerson;
        //personNode * clipboard;
        FamilyTree * curft;
        FileIO fio;

    public:
        Model();
        ~Model();
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
        /*
        Name serializeName();
        Addr serializeBirthAddr();
        PDate serializeBirthDate();
        Addr serializeDeathAddr();
        PDate serializeDeathDate();
        */
};

#endif // MODEL_H
