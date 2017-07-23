//=========================================================================
// Name        : fileio.c
// Author      : Michael Louie
// Description : Handles file input/output for tree states using GEDCOM 5.5
//=========================================================================
#include "fileio.h"

FileIO::FileIO()
{
//file object
}

/*
 * Opens file.
 */
void FileIO::openFile(char * filePath) {
    //file ob.open(
}

/*
 * Closes file.
 */
void FileIO::closeFile() {
    //file ob.close();
}

/*
 * Commits changes to file.
 */
void FileIO::saveFile() {
    //clear file (what if something happens midway???)
    //write many times to it
}

void FileIO::clearFileName() {
    filename = "";
}
