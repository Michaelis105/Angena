//============================================================================
// Name        : main.cpp
// Author      : Michael Louie
// Description : main
//============================================================================
#include "angena.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Angena w;
    w.show();
    return a.exec();
}
