//============================================================================
// Name        : file_io.h
// Author      : Michael Louie
// Description : Header for the file input/output.
//============================================================================

#ifndef FILE_IO_H
#define FILE_IO_H
#include <fstream>

class file_io
{
    public:
        file_io();

        void open_file(char * file_path);

        void close_file();

        void save_file();
    };
#endif // FILE_IO_H
