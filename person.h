//============================================================================
// Name        : person.h
// Author      : Michael Louie
// Description : Header for the person data unit.
//============================================================================
#ifndef PERSON_H
#define PERSON_H

class person
{
    private:
        char * title;
        char * first_name;
        char * middle_name;
        char * last_name;
        char * nick_name;
        char * suffix;
        char * gender; // make enum to declare all identifiable genders.

        char * home_addr;
        char * birth_place_state;
        char * birth_place_city;
        char * birth_place_country;

        char * death_addr;
        char * death_place_state;
        char * death_place_city;
        char * death_place_country;

        bool isAlive; // make this an enum

        int birth_month;
        int birth_day;
        int birth_year;

        int death_month;
        int death_day;
        int death_year;

        char * notes;

    public:
        person();
        updatePerson();
};

#endif // PERSON_H
