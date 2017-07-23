//==========================================
// Name        : model.h
// Author      : Michael Louie
// Description : Header for the Angena model
//==========================================
#ifndef MODEL_H
#define MODEL_H

#include <QUuid>
#include <vector>
#include <stdexcept>

#include "familyTree.h"
#include "fileIO.h"

class Model
{
    private:
        PersonNode * curSelPerson;
        FamilyTree * curft;
        FileIO fio;
        //personNode * clipboard;

    public:
        Model();
        void initializeNewFamilyTree();
        void addPerson();
        void delPerson();
        void editPerson(vector<string> names, string sex,
                        vector<string> birthDate, vector<string> birthAddr,
                        string notes, vector<string> deathDate,
                        vector<string> deathAddr, bool living);
        void connectPerson();
        void disconnectPerson();
        void undo();
        void redo();
        void clearTreeState();
        void openTreeState();
        void saveTreeState();
        bool isTreeOpen();
        bool isCurSelPerson();
        void cleanUp();
};

#endif // MODEL_H
