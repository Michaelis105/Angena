//================================
// Name        : personaddress.cpp
// Author      : Michael Louie
// Description : Holds address
//================================
#include "personaddress.h"

PersonAddress::PersonAddress()
{
    homeAddr = new string();
    stateProv = new string();
    city = new string();
    country = new string();
    zipCode = new string();
}

PersonAddress::PersonAddress(string ha, string sp, string ciy, string coy, string zc)
{
    homeAddr = new string(ha);
    stateProv = new string(sp);
    city = new string(ciy);
    country = new string(coy);
    zipCode = new string(zc);
}

PersonAddress::~PersonAddress() {
    delete homeAddr;
    delete stateProv;
    delete city;
    delete country;
    delete zipCode;
}

/**
 * @brief Sets home address of person.
 * @param newHomeAddr (can be empty)
 */
void PersonAddress::setHomeAddr(string newHomeAddr) {
    *homeAddr = newHomeAddr;
}

/**
 * @brief Sets state/province of person.
 * @param newStateProv (can be empty)
 */
void PersonAddress::setStateProv(string newStateProv) {
    *stateProv = newStateProv;
}

/**
 * @brief Sets city of person.
 * @param newCity (can be empty)
 */
void PersonAddress::setCity(string newCity) {
    *city = newCity;
}

/**
 * @brief Sets country of person.
 * @param newCountry (can be empty)
 */
void PersonAddress::setCountry(string newCountry) {
    *country = newCountry;
}

/**
 * @brief Sets zip code of person.
 * @param newZipCode (can be empty)
 */
void PersonAddress::setZipCode(string newZipCode) {
    *zipCode = newZipCode;
}

/**
 * @brief Gets home address of person.
 * @return home address (can be empty)
 */
string PersonAddress::getHomeAddr() {
    return *homeAddr;
}

/**
 * @brief Gets state/province of person.
 * @return state/province (can be empty)
 */
string PersonAddress::getStateProv() {
    return *stateProv;
}

/**
 * @brief Gets city of person.
 * @return city (can be empty)
 */
string PersonAddress::getCity() {
    return *city;
}

/**
 * @brief Gets country of person.
 * @return country (can be empty)
 */
string PersonAddress::getCountry() {
    return *country;
}

/**
 * @brief Gets zip code of person.
 * @return zip code (can be empty)
 */
string PersonAddress::getZipCode() {
    return *zipCode;
}
