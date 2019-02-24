//
// Created by bear on 24.02.19.
//

#include "FileInput.h"

FileInput::~FileInput()
{
    dispose();
}

FileInput::FileInput(const string &name) : File(name)
{
    this->stream = new ifstream(name);
}

void FileInput::dispose()
{
    if(stream != nullptr)
    {
        stream->close();
        delete stream;
        stream = nullptr;
    }
}

string FileInput::readAll()
{
    stringstream str;
    str << stream->rdbuf();
    return str.str();
}

string FileInput::readLine()
{
    string str;
    getline(*stream, str);
    return str;
}
