//
// Created by bear on 25.02.19.
//

#include "FileBinaryInput.h"

FileBinaryInput::FileBinaryInput(const string &name) : File(name)
{
    this->stream = new ifstream(name, ios::binary | ios::in);
}

void FileBinaryInput::dispose()
{
    if(stream != nullptr)
    {
        stream->close();
        delete stream;
        stream = nullptr;
    }
}

FileBinaryInput::~FileBinaryInput()
{
    dispose();
}

vector<char> FileBinaryInput::readAll()
{
    vector<char> dataArray;
    long filesize = getFileSize();
    if(filesize == -1) return {};
    dataArray.resize((unsigned long)filesize);
    *stream >> dataArray.data();
    return dataArray;
}
