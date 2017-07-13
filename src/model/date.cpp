//========================================
// Name        : date.cpp
// Author      : Michael Louie
// Description : Date (MM/DD/YYYY)
//========================================
#include "date.h"

Date::Date()
{
    month = new unsigned char;
    day = new unsigned char;
    year = new short;
}

Date::~Date() {
    delete month;
    delete day;
    delete year;
}

/**
 * @brief Sets month of month.
 * @param newMonth (0 = Unknown, 1-12)
 */
void Date::setMonth(unsigned char newMonth) {
    if (newMonth <= 12) {
        *month = newMonth;
    } else {
        throw std::invalid_argument( "New month should be between 1 and 12 inclusive or 0 for unknown." );
    }
}

/**
 * @brief Sets day of date.
 * @param newDay (0 = Unknown, 1-31)
 */
void Date::setDay(unsigned char newDay) {
    if (newDay <= 31) {
        *day = newDay;
    } /*else if {
       // TODO: Check if day corresponds with month 30-31 and Feb's 28-29
    }*/ else {
        throw std::invalid_argument( "New day should be between 1 and 31 inclusive or 0 for unknown." );
    }
}

/**
 * @brief Sets year of date.
 * @param newYear (<0 = BCE, >=0 = CE)
 */
void Date::setYear(short newYear) {
    *year = newYear;
}

/**
 * @brief Gets month of date.
 * @return value of month (0 = Unknown, 1-12)
 */
unsigned char Date::getMonth() {
    return *month;
}

/**
 * @brief Gets day of date.
 * @return value of day (0 = Unknown, 1-31)
 */
unsigned char Date::getDay() {
    return *day;
}

/**
 * @brief Gets year of date.
 * @return value of day (<0 = BCE, >=0 = CE)
 */
short Date::getYear() {
    return *year;
}
