//====================================
// Name        : personaddress.cpp
// Author      : Michael Louie
// Description : Holds person name data
//=====================================
#include "personname.h"

PersonName::PersonName()
{
    title = new string();
    firstName = new string();
    middleName = new string();
    lastName = new string();
    nickName = new string();
}

PersonName::~PersonName() {
    delete title;
    delete firstName;
    delete middleName;
    delete lastName;
    delete nickName;
}

/**
 * @brief Sets title of person.
 * @param newTitle (can be empty)
 */
void PersonName::setTitle(string newTitle) {
    *title = newTitle;
}

/**
 * @brief Sets first name of person.
 * @param newFirstName (can be empty)
 */
void PersonName::setFirstName(string newFirstName) {
    *firstName = newFirstName;
}

/**
 * @brief Sets middle name of person.
 * @param newMiddleName (can be empty)
 */
void PersonName::setMiddleName(string newMiddleName) {
    *middleName = newMiddleName;
}

/**
 * @brief Sets last name of person.
 * @param newLastName (can be empty)
 */
void PersonName::setLastName(string newLastName) {
    *lastName = newLastName;
}

/**
 * @brief Sets nick name of person.
 * @param newNickName (can be empty)
 */
void PersonName::setNickName(string newNickName) {
    *nickName = newNickName;
}

/**
 * @brief Sets suffix of person.
 * @param newSuffix (can be empty)
 */
void PersonName::setSuffix(string newSuffix) {
    *suffix = newSuffix;
}

/**
 * @brief Gets title of person.
 * @return title (can be empty)
 */
string PersonName::getTitle() {
    return *title;
}

/**
 * @brief Gets first name of person.
 * @return first name (can be empty)
 */
string PersonName::getFirstName() {
    return *firstName;
}

/**
 * @brief Gets middle name of person.
 * @return middle name (can be empty)
 */
string PersonName::getMiddleName() {
    return *middleName;
}

/**
 * @brief Gets last name of person.
 * @return last name (can be empty)
 */
string PersonName::getLastName() {
    return *lastName;
}

/**
 * @brief Gets nick name of person.
 * @return nick name (can be empty)
 */
string PersonName::getNickName() {
    return *nickName;
}

/**
 * @brief Gets suffix of person.
 * @return suffix (can be empty)
 */
string PersonName::getSuffix() {
    return *suffix;
}
