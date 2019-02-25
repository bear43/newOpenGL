//
// Created by bear on 24.02.19.
//

#include "File.h"

File::File(const string &name)
{
    this->name = name;
}

long File::getFileSize()
{
    ifstream stream(name, ios::binary | ios::ate);
    if(!stream.is_open())
    {
        stream.close();
        return -1;
    }
    long size = stream.tellg();
    stream.close();
    return size;
}
