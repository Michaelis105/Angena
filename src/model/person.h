//===============================================
// Name        : person.h
// Author      : Michael Louie
// Description : Header for the person data unit.
//===============================================
#ifndef PERSON_H
#define PERSON_H

#include <vector>
// Is there a better way to dynamically store name besides vector?
// Vector destructs once popped off stack!!!
typedef std::vector<char> DynName;
struct name
{
    DynName title;
    DynName first_name;
    DynName middle_name;
    DynName last_name;
    DynName nick_name;
    DynName suffix;
}; typedef struct name Name;

struct addr
{
    DynName home_addr;
    char * state_prov;
    DynName city;
    char * country;
}; typedef struct addr Addr;

typedef unsigned char n0255; // 0-255
struct Date
{
    n0255 * month;
    n0255 * day;
    n0255 * year;
}; typedef struct Date PDate;

enum Gender { MALE, FEMALE, OTHER, G_UNKNOWN };
enum LivingState { ALIVE, DECEASED, LS_UNKNOWN };

class Person
{
    private:
        Name * name;
        Gender gender;
        Addr * birth_addr;
        Addr * death_addr;
        PDate * birth_date;
        PDate * death_date;
        LivingState livingState;
        DynName * notes;

    public:
        Person();
        void setName(Name* newName);
        void setBirthAddr(Addr* newBAddr);
        void setDeathAddr(Addr* newDAddr);
        void setBirthDate(PDate* newBDate);
        void setDeathDate(PDate* newDDate);
        void setAliveStatus(LivingState state);
        void setNotes(char * newNote);
        Name* getName();
        Addr* getBirthAddr();
        Addr* getDeathAddr();
        PDate* getBirthDate();
        PDate* getDeathDate();
        LivingState getAliveStatus();
        DynName getNotes();
        ~Person();
};

#endif // PERSON_H
