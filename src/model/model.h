//==========================================
// Name        : model.h
// Author      : Michael Louie
// Description : Header for the Angena model
//==========================================
#ifndef MODEL_H
#define MODEL_H

#include <QUuid>
#include <vector>

#include "familyTree.h"
#include "fileIO.h"

class Model
{
    private:
        PersonNode * curSelPerson;
        FamilyTree curft;
        FileIO fio;
        //personNode * clipboard;

    public:
        Model();
        ~Model();
        void addPerson();
        void delPerson();
        void editPerson();
        void connectPerson();
        void disconnectPerson();
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
