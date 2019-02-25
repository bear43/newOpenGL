//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_FILEINPUT_H
#define UNTITLED2_FILEINPUT_H

#include "../File.h"
#include <sstream>

class FileStringInput : File
{
private:
    ifstream *stream = nullptr;
    void dispose();
public:
    explicit FileStringInput(const string &name);
    virtual ~FileStringInput();

    string readAll();
    string readLine();
};


#endif //UNTITLED2_FILEINPUT_H
