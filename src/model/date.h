//===============================
// Name        : person.cpp
// Author      : Michael Louie
// Description : Holds date info.
//===============================
#ifndef DATE_H
#define DATE_H

#include <stdexcept>

class Date
{
    private:
        unsigned char * month;
        unsigned char * day;
        short * year;
    public:
        Date();
        ~Date();
        void setMonth(unsigned char newMonth);
        void setDay(unsigned char newDay);
        void setYear(short newYear);
        unsigned char getMonth();
        unsigned char getDay();
        short getYear();
};

#endif // DATE_H
