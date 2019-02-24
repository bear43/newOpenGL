//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_FILE_H
#define UNTITLED2_FILE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class File
{
protected:
    string name;
public:
    explicit File(const string &name);
};


#endif //UNTITLED2_FILE_H
