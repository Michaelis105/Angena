//================================================
// Name        : fileio.h
// Author      : Michael Louie
// Description : Header for the file input/output.
//================================================
#ifndef FILEIO_H
#define FILEIO_H
#include <fstream>

class FileIO
{
    public:
        FileIO();
        void openFile(char * filePath);
        void closeFile();
        void saveFile();
};

#endif // FILEIO_H
