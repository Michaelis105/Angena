//================================================
// Name        : fileio.h
// Author      : Michael Louie
// Description : Header for the file input/output.
//================================================
#ifndef FILEIO_H
#define FILEIO_H
#include <string>
#include <fstream>

using namespace std;

class FileIO
{
    private:
        string filename;
    public:
        FileIO();
        void openFile(char * filePath);
        void closeFile();
        void saveFile();
        void clearFileName();
};

#endif // FILEIO_H
