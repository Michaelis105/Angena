//===============================================
// Name        : person.h
// Author      : Michael Louie
// Description : Header for the person data unit.
//===============================================
#ifndef PERSON_H
#define PERSON_H
#include <vector>
#include <string>
#include <stdexcept>
#include "personname.h"
#include "personaddress.h"
#include "date.h"

using namespace std;

//enum Sex { MALE, FEMALE, OTHER, G_UNKNOWN };
//enum LivingState { ALIVE, DECEASED, LS_UNKNOWN };

class Person
{
    private:
        PersonName * name;
        string * sex;
        PersonAddress * birthAddr;
        PersonAddress * deathAddr;
        Date * birthDate;
        Date * deathDate;
        string * livingState;
        string * notes;

    public:
        Person();
        ~Person();
        void setNames(vector<string> names);
        void setBirthAddr(vector<string> addrs);
        void setDeathAddr(vector<string> addrs);
        void setBirthDate(vector<string> dates);
        void setDeathDate(vector<string> dates);
        void setLivingStatus(string state);
        void setNotes(string newNote);
        PersonName* getName();
        PersonAddress* getBirthAddr();
        PersonAddress* getDeathAddr();
        Date* getBirthDate();
        Date* getDeathDate();
        string getLivingStatus();
        string getNotes();
};

#endif // PERSON_H
