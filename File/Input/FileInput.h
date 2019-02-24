//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_FILEINPUT_H
#define UNTITLED2_FILEINPUT_H

#include "../File.h"
#include <sstream>

class FileInput : File
{
private:
    ifstream *stream = nullptr;
    void dispose();
public:
    explicit FileInput(const string &name);
    virtual ~FileInput();

    string readAll();
    string readLine();
};


#endif //UNTITLED2_FILEINPUT_H
