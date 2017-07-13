//========================================================
// Name        : person.cpp
// Author      : Michael Louie
// Description : Basic person data unit for a family tree.
//========================================================
#include "person.h"
using namespace std;

/*
 * Creates new person with no information.
 */
Person::Person() {
    name = new PersonName();
    gender = G_UNKNOWN;
    birth_addr = new PersonAddress();
    birth_date = new Date();
    death_addr = new PersonAddress();
    death_date = new Date();
    livingState = LS_UNKNOWN;
    notes = new string();
}

// TODO: Add another constructor for all details.
// TODO: Fix setters and getters.

/*
 * Sets person's name.
 */
void Person::setName(string names) {
    // call each setter
}

/*
 * Sets birth address.
 */
void Person::setBirthAddr(string addrs) {
    // call each setter
}

/*
 * Sets death address.
 */
void Person::setDeathAddr(string addrs) {

}

/*
 * Sets birth date.
 */
void Person::setBirthDate() {

}

/*
 * Sets death date.
 */
void Person::setDeathDate() {

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
void Person::setNotes(string newNote) {
    //notes = newNote;
}

Person::~Person() {
    delete name;
    delete birth_addr;
    delete birth_date;
    delete death_addr;
    delete death_date;
}
