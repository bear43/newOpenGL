//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_FILEOUTPUT_H
#define UNTITLED2_FILEOUTPUT_H


#include "../File.h"


class FileOutput : File
{
private:
    static constexpr char terminator = '\n';
    ofstream *stream = nullptr;
    void dispose();
public:
    explicit FileOutput(const string &name);

    virtual ~FileOutput();
    void writeAll(const string &data);
    void writeLine(const string &data);
};


#endif //UNTITLED2_FILEOUTPUT_H
