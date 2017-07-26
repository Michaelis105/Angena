//================================================
// Name        : fileio.h
// Author      : Michael Louie
// Description : Header for the file input/output.
//================================================
#ifndef FILEIO_H
#define FILEIO_H
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

class FileIO
{
    private:
        string filename;
        ifstream roFile;
        ofstream woFile;
    public:
        FileIO();
        void openFile(string newFilename, bool isRO);
        string readLine();
        void clearFileName();
        void writeLine(string s);
        void closeFileRW();
};

#endif // FILEIO_H
