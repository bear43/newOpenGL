//
// Created by bear on 24.02.19.
//

#include "FileStringInput.h"

FileStringInput::~FileStringInput()
{
    dispose();
}

FileStringInput::FileStringInput(const string &name) : File(name)
{
    this->stream = new ifstream(name);
}

void FileStringInput::dispose()
{
    if(stream != nullptr)
    {
        stream->close();
        delete stream;
        stream = nullptr;
    }
}

string FileStringInput::readAll()
{
    stringstream str;
    str << stream->rdbuf();
    return str.str();
}

string FileStringInput::readLine()
{
    string str;
    getline(*stream, str);
    return str;
}
