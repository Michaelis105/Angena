//=======================================================
// Name        : personname.h
// Author      : Michael Louie
// Description : Header for the person name data unit.
//=======================================================
#ifndef PERSONNAME_H
#define PERSONNAME_H

#include <string>

using namespace std;

class PersonName
{
    private:
        string * title;
        string * firstName;
        string * middleName;
        string * lastName;
        string * nickName;
        string * suffix;
    public:
        PersonName();
        ~PersonName();
        void setTitle(string newTitle);
        void setFirstName(string newfirstName);
        void setMiddleName(string newMiddleName);
        void setLastName(string newLastName);
        void setNickName(string newNickName);
        void setSuffix(string newSuffix);
        string getTitle();
        string getFirstName();
        string getMiddleName();
        string getLastName();
        string getNickName();
        string getSuffix();
};

#endif // PERSONNAME_H
