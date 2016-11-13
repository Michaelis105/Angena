//============================================================================
// Name        : person.h
// Author      : Michael Louie
// Description : Header for the person data unit.
//============================================================================
#ifndef PERSON_H
#define PERSON_H
#include <vector>
// Is there a better way to dynamically store name besides vector?
// Vector destructs once popped off stack!!!
typedef std::vector<char> dyn_name;
struct name
{
    dyn_name title;
    dyn_name first_name;
    dyn_name middle_name;
    dyn_name last_name;
    dyn_name nick_name;
    dyn_name suffix;
}; typedef struct name Name;

struct addr
{
    dyn_name home_addr;
    char * state_prov;
    dyn_name city;
    char * country;
}; typedef struct addr Addr;

typedef unsigned char n0255; // 0-255
struct date
{
    n0255 * month;
    n0255 * day;
    n0255 * year;
}; typedef struct date p_Date;

enum Gender
{
    male, female,
    other, // the other 20+ genders.
    g_unknown
};

enum LivingState
{
    alive, deceased, s_unknown
};

class person
{
    private:
        Name * name;
        Gender gender;
        Addr * birth_addr;
        Addr * death_addr;
        p_Date * birth_date;
        p_Date * death_date;
        bool isAlive;
        dyn_name * notes;

    public:
        person(bool isDeceased);
        void updateName(Name* newName);
        void updateBirthAddr(Addr* newBAddr);
        void updateDeathAddr(Addr* newDAddr);
        void updateBirthDate(p_Date* newBDate);
        void updateDeathDate(p_Date* newDDate);
        void updateAliveStatus(bool state);
        void updateNotes(char * newNote);
        ~person();
};

#endif // PERSON_H
