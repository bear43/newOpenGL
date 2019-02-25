//
// Created by bear on 25.02.19.
//

#ifndef UNTITLED2_FILEBINARYINPUT_H
#define UNTITLED2_FILEBINARYINPUT_H


#include "../File.h"
#include <vector>

using namespace std;

class FileBinaryInput : public File
{
private:
    ifstream *stream = nullptr;
    void dispose();
public:
    explicit FileBinaryInput(const string &name);
    virtual ~FileBinaryInput();

    vector<char> readAll();
};


#endif //UNTITLED2_FILEBINARYINPUT_H
