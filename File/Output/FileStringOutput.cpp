//
// Created by bear on 24.02.19.
//

#include "FileStringOutput.h"

FileStringOutput::FileStringOutput(const string &name) : File(name)
{
    this->stream = new ofstream(name);
}

FileStringOutput::~FileStringOutput()
{
    dispose();
}

void FileStringOutput::dispose()
{
    if(stream != nullptr)
    {
        stream->flush();
        stream->close();
        delete stream;
        stream = nullptr;
    }
}

void FileStringOutput::writeAll(const string &data)
{
    *stream << data;
    stream->flush();
}

void FileStringOutput::writeLine(const string &data)
{
    writeAll(data);
    *stream << terminator;
}
