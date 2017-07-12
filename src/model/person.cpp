//========================================================
// Name        : person.cpp
// Author      : Michael Louie
// Description : Basic person data unit for a family tree.
//========================================================
#include "person.h"
using namespace std;

/*
 * Creates new person with no information.
 * Possibly an unknown person that is part of a family tree.
 * TODO: Check correct allocations.
 */
Person::Person() {
    name = new Name;
    gender = G_UNKNOWN;
    birth_addr = new Addr;
    birth_addr->state_prov = new char[2];
    birth_addr->country = new char[2];

    birth_date = new PDate;
    birth_date->month = new n0255;
    birth_date->day = new n0255;
    birth_date->year = new n0255;

    // Allocate death information if actually deceased.
    death_addr = new Addr;
    death_addr->state_prov = new char[2];
    death_addr->country = new char[2];
    death_date = new PDate;
    death_date->month = new n0255;
    death_date->day = new n0255;
    death_date->year = new n0255;
    livingState = LS_UNKNOWN;

    // Memory allocation check.
}

/*
 * Sets person's name.
 */
void Person::setName(Name* newName) {
    if (newName != nullptr) {
        name->first_name = newName->first_name;
        name->middle_name = newName->middle_name;
        name->last_name = newName->last_name;
    }
}

/*
 * Sets birth address.
 */
void Person::setBirthAddr(Addr* newBAddr) {
    if (newBAddr != nullptr) {
        birth_addr->home_addr = newBAddr->home_addr;
        birth_addr->state_prov = newBAddr->state_prov;
        birth_addr->city = newBAddr->city;
        birth_addr->country = newBAddr->country;
    }
}

/*
 * Sets death address.
 */
void Person::setDeathAddr(Addr* newDAddr) {

}

/*
 * Sets birth date.
 */
void Person::setBirthDate(PDate* newBDate) {

}

/*
 * Sets death date.
 */
void Person::setDeathDate(PDate* newDDate) {

}

/*
 * Sets living status.
 */
void Person::setAliveStatus(LivingState state) {
    livingState = state;
    // Destroy deceased information.
}

/*
 * Sets notes.
 */
void Person::setNotes(char * newNote) {
    //notes = newNote;
}

// TODO: Check coorect deallocations.
Person::~Person() {
    // How to deallocate vectors? Is it automatic?
    delete name;

    delete birth_addr->state_prov;
    delete birth_addr->country;
    delete birth_addr;

    delete birth_date->month;
    delete birth_date->day;
    delete birth_date->year;
    delete birth_date;

    // Prevents deallocation of non-allocated data for deceased.
    if (livingState == DECEASED) {
        delete death_addr->state_prov;
        delete death_addr->country;
        delete death_addr;

        delete death_date->month;
        delete death_date->day;
        delete death_date->year;
        delete death_date;
    }
}
