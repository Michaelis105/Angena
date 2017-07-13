//===============================================
// Name        : person.h
// Author      : Michael Louie
// Description : Header for the person data unit.
//===============================================
#ifndef PERSON_H
#define PERSON_H
#include <vector>
#include <string>
#include "personname.h"
#include "personaddress.h"
#include "date.h"

enum Gender { MALE, FEMALE, OTHER, G_UNKNOWN };
enum LivingState { ALIVE, DECEASED, LS_UNKNOWN };

class Person
{
    private:
        PersonName * name;
        Gender gender;
        PersonAddress * birth_addr;
        PersonAddress * death_addr;
        Date * birth_date;
        Date * death_date;
        LivingState livingState;
        string * notes;

    public:
        Person();
        ~Person();
        void setName(string names);
        void setBirthAddr(string addrs);
        void setDeathAddr(string addrs);
        void setBirthDate();
        void setDeathDate();
        void setAliveStatus(LivingState state);
        void setNotes(string newNote);
        PersonName* getName();
        PersonAddress* getBirthAddr();
        PersonAddress* getDeathAddr();
        Date* getBirthDate();
        Date* getDeathDate();
        LivingState getAliveStatus();
        string getNotes();
};

#endif // PERSON_H
