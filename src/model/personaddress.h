//======================================================
// Name        : personaddress.h
// Author      : Michael Louie
// Description : Header for the person address data unit
//======================================================
#ifndef PERSONADDRESS_H
#define PERSONADDRESS_H
#include <string>

using namespace std;

class PersonAddress
{
    private:
        string * homeAddr;
        string * stateProv;
        string * city;
        string * country;
        string * zipCode;
    public:
        PersonAddress();
        PersonAddress(string ha, string sp, string ciy, string coy, string zc);
        ~PersonAddress();
        void setHomeAddr(string newHomeAddr);
        void setStateProv(string newStateProv);
        void setCity(string newCity);
        void setCountry(string newCountry);
        void setZipCode(string newZipCode);
        string getHomeAddr();
        string getStateProv();
        string getCity();
        string getCountry();
        string getZipCode();
};

#endif // PERSONADDRESS_H
