//============================================================================
// Name        : person.cpp
// Author      : Michael Louie
// Description : Basic person data unit for a family tree.
//============================================================================
#include "person.h"
using namespace std;

/*
 * Creates new person with no information.
 * Possibly an unknown person that is part of a family tree.
 * TODO: Check correct allocations.
 */
person::person(bool isDeceased) {
    name = new Name;
    //gender = Gender.g_unknown;
    birth_addr = new Addr;
    birth_addr->state_prov = new char[2];
    birth_addr->country = new char[2];

    birth_date = new p_Date;
    birth_date->month = new n0255;
    birth_date->day = new n0255;
    birth_date->year = new n0255;

    // Allocate death information if actually deceased.
    if (isDeceased) {
        death_addr = new Addr;
        death_addr->state_prov = new char[2];
        death_addr->country = new char[2];

        death_date = new p_Date;
        death_date->month = new n0255;
        death_date->day = new n0255;
        death_date->year = new n0255;
    }

    isAlive = !isDeceased;

    if (!name || !birth_addr || !birth_date || !death_addr || !death_date) {
        // Memory allocation error!
    }
}

void person::updateName(Name* newName) {
    if ((newName != nullptr) && (name != nullptr)) {
        name->first_name = newName->first_name;
        name->middle_name = newName->middle_name;
        name->last_name = newName->last_name;
    }
}

void person::updateBirthAddr(Addr* newBAddr) {

}

void person::updateDeathAddr(Addr* newDAddr) {

}

void person::updateBirthDate(p_Date* newBDate) {

}

void person::updateDeathDate(p_Date* newDDate) {

}

void person::updateAliveStatus(bool state) {
    isAlive = state;
    // Destroy deceased information.
}

void person::updateNotes(char * newNote) {
    //notes = newNote;
}

// TODO: Check coorect deallocations.
person::~person() {
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
    if (!isAlive) {
        delete death_addr->state_prov;
        delete death_addr->country;
        delete death_addr;

        delete death_date->month;
        delete death_date->day;
        delete death_date->year;
        delete death_date;
    }
}
