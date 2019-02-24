//
// Created by bear on 24.02.19.
//

#include "FileOutput.h"

FileOutput::FileOutput(const string &name) : File(name)
{
    this->stream = new ofstream(name);
}

FileOutput::~FileOutput()
{
    dispose();
}

void FileOutput::dispose()
{
    if(stream != nullptr)
    {
        stream->flush();
        stream->close();
        delete stream;
        stream = nullptr;
    }
}

void FileOutput::writeAll(const string &data)
{
    *stream << data;
    stream->flush();
}

void FileOutput::writeLine(const string &data)
{
    writeAll(data);
    *stream << terminator;
}
