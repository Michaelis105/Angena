//=======================================================
// Name        : person.cpp
// Author      : Michael Louie
// Description : Basic person data unit for a family tree
//=======================================================
#include "person.h"

/**
 * @brief Intended when creating a new person.
 */
Person::Person() {
    name = new PersonName();
    sex = new string();
    birthAddr = new PersonAddress();
    birthDate = new Date();
    deathAddr = new PersonAddress();
    deathDate = new Date();
    //livingState = LS_UNKNOWN;
    livingState = new string();
    notes = new string();
}

/**
 * @brief Intended when creating a new person.
 */
Person::~Person() {
    delete name;
    delete birthAddr;
    delete birthDate;
    delete deathAddr;
    delete deathDate;
}

/**
 * @brief Sets names corresponding to names index.
 * @param names list of names, must be size 6
 *        [0] = title, [1] = first name, etc...
 */
void Person::setNames(vector<string> names) {
    if (names.size() == 6) {
        name->setTitle(names.at(0));
        name->setFirstName(names.at(1));
        name->setMiddleName(names.at(2));
        name->setLastName(names.at(3));
        name->setNickName(names.at(4));
        name->setSuffix(names.at(5));
    } else {
        throw invalid_argument( "Person::setNames(): Names should be size 6. See method briefing for details." );
    }
}

/**
 * @brief Sets sex
 * @param s person's sex
 */
void Person::setSex(string s) {
    *sex = s;
}

/**
 * @brief Sets birth address parts corresponding to addrs index.
 * @param addrs list of address parts, must be size 5
 *        [0] = home address, [1] = state/province, etc...
 */
void Person::setBirthAddr(vector<string> addrs) {
    if (addrs.size() == 5) {
        birthAddr->setHomeAddr(addrs.at(0).c_str());
        birthAddr->setStateProv(addrs.at(1));
        birthAddr->setCity(addrs.at(2));
        birthAddr->setCountry(addrs.at(3));
        birthAddr->setZipCode(addrs.at(4));
    } else {
        throw invalid_argument( "Person::setBirthAddr(): Addrs should be size 5. See method briefing for details." );
    }
}

/**
 * @brief Sets death address parts corresponding to addrs index.
 * @param addrs list of address parts, must be size 5
 *        [0] = home address, [1] = state/province, etc...
 */
void Person::setDeathAddr(vector<string> addrs) {
    if (addrs.size() == 5) {
        deathAddr->setHomeAddr(addrs.at(0));
        deathAddr->setStateProv(addrs.at(1));
        deathAddr->setCity(addrs.at(2));
        deathAddr->setCountry(addrs.at(3));
        deathAddr->setZipCode(addrs.at(4));
    } else {
        throw invalid_argument( "Person::setDeathAddr(): Addrs should be size 5. See method briefing for details." );
    }
}

/**
 * @brief Sets birth date parts corresponding to dates index.
 * @param dates list of date parts, must be size 3
 *        [0] = month, [1] = day, [2] = year
 */
void Person::setBirthDate(vector<string> dates) {
    if (dates.size() == 3) {
        birthDate->setMonth(stoi(dates.at(0)));
        birthDate->setDay(stoi(dates.at(1)));
        birthDate->setYear(stoi(dates.at(2)));
    } else {
        throw invalid_argument( "Person::setBirthDate(): Dates should be size 3. See method briefing for details." );
    }
}

/**
 * @brief Sets death date parts corresponding to dates index.
 * @param dates list of date parts, must be size 3
 *        [0] = month, [1] = day, [2] = year
 */
void Person::setDeathDate(vector<string> dates) {
    if (dates.size() == 3) {
        deathDate->setMonth(stoi(dates.at(0)));
        deathDate->setDay(stoi(dates.at(1)));
        deathDate->setYear(stoi(dates.at(2)));
    } else {
        throw invalid_argument( "Person::setDeathDate(): Dates should be size 3. See method briefing for details." );
    }
}

/**
 * @brief Sets living status.
 * @param state living status (common: alive, deceased, unknown)
 */
void Person::setLivingStatus(string state) {
    *livingState = state;
}

/**
 * @brief Sets stored other notes.
 * @param newNote notes for person
 */
void Person::setNotes(string newNote) {
    *notes = newNote;
}

/**
 * @brief Gets person's name.
 * @return name
 */
PersonName* Person::getName() {
    return name;
}

/**
 * @brief Gets person's sex.
 * @return sex
 */
string* Person::getSex() {
    return sex;
}

/**
 * @brief Gets person's birth address.
 * @return birth address
 */
PersonAddress* Person::getBirthAddr() {
    return birthAddr;
}

/**
 * @brief Gets person's death address.
 * @return death address
 */
PersonAddress* Person::getDeathAddr() {
    return deathAddr;
}

/**
 * @brief Get person's birth date.
 * @return birth date
 */
Date* Person::getBirthDate() {
    return birthDate;
}

/**
 * @brief Gets person's death date.
 * @return death date
 */
Date* Person::getDeathDate() {
    return deathDate;
}

/**
 * @brief Gets person's living status.
 * @return living status
 */
string* Person::getLivingStatus() {
    return livingState;
}

/**
 * @brief Gets person's notes.
 * @return notes
 */
string* Person::getNotes() {
    return notes;
}
