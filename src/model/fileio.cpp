//======================================================================
// Name        : fileio.c
// Author      : Michael Louie
// Description : Handles file input/output for Angena-specific use cases
//======================================================================
#include "fileio.h"

FileIO::FileIO() { }

/**
 * @brief Opens file in specific mode.
 *        File IO will always clean file before writing.
 * @param ro read-only if true, write-only false
 */
void FileIO::openFile(string newFilename, bool isRO) {
    if (newFilename.size() == 0) {
        throw logic_error("FileIO::openFile(): Filename is empty!");
    }
    if (isRO) {
        if (roFile.is_open()) throw logic_error("FileIO::openFile(): fileRO already opened!");
        roFile.open(filename);
    } else {
        if (woFile.is_open()) throw logic_error("FileIO::openFile(): fileRW already opened!");
        woFile.open(filename, ios::trunc);
    }
    filename = newFilename;
}

/**
 * @brief Reads a line from RO file. After all lines read, closes file.
 * @pre roFile already opened and as read-only
 * @post caller has all lines, fileRO closed
 */
string FileIO::readLine() {
    if (!roFile.is_open()) {
        throw logic_error("FileIO::readLine(): roFile has not been opened!");
    }
    string line;
    if(getline(roFile, line)) {
        return line;
    }
    roFile.close(); // Model does not need to read file any more,
                    // just conveniently close it here.
    return NULL; // Caller should handle NULL as "EOF" indicator.
}

/**
 * @brief Writes line to file. Intended to be called multiple times when saving once to file
 * @param s line string to write to file, can be empty
 */
void FileIO::writeLine(string s) {
    if (!woFile.is_open()) {
        throw logic_error("FileIO::writeLine(): rwFile has not been opened!");
    }
    woFile << s << endl;
}

/**
 * @brief Clears stored filename. Usually if done writing  and family tree closed from model.
 */
void FileIO::clearFileName() {
    filename = "";
}

/**
 * @brief Closes write-only file. Usually if done writing to file.
 */
void FileIO::closeFileRW() {
    if (!woFile.is_open()) {
        throw logic_error("FileIO::closeFileRW(): woFile is not open!");
    }
    woFile.close();
}



