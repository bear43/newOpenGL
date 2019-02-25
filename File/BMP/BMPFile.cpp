//
// Created by bear on 25.02.19.
//

#include "BMPFile.h"

BMPFile::BMPFile(const string &name) : File(name)
{}

void BMPFile::set(const char *name)
{
    this->name = name;
}

void BMPFile::set(const string &name)
{
    this->name = name;
}

int BMPFile::load()
{
    long filesize = 0;
    FILE* img = fopen(name.c_str(), "rb");
    if(img == nullptr) return FILE_DIDNOTOPEN;
    fseek(img, 0, SEEK_SET);
    if(fread(&header, 1, sizeof(BMP), img) != sizeof(BMP))
    {
        fclose(img);
        return FILE_IO;
    }
    if(header.Signature != 0x4D42 && header.Signature != 0x4349 && header.Signature != 0x5450)
    {
        fclose(img);
        return FILE_NOTBMP;
    }
    fseek(img, 0, SEEK_END);
    filesize = ftell(img);
    fseek(img, sizeof(BMP), SEEK_SET);
    if(header.Filesize != filesize || header.Reserved !=0 || header.Planecount != 1 || (header.Structsize != 40 && header.Structsize != 108 && header.Structsize != 124))
    {
        fclose(img);
        return _FILE_UNKNOWN;
    }
    if(header.Bitcount == 32)
    {
        fclose(img);
        return FILE_NOTSUPPORT;
    }
    Data.resize((unsigned long)filesize);
    fseek(img, header.Offset, SEEK_SET);
    if(fread(Data.data(), 1, (size_t)header.ImageSize, img) != (size_t)header.ImageSize)
    {
        fclose(img);
        return FILE_IO;
    }
    fclose(img);
    return FILE_SUCCESSFUL;
}

const vector<char> &BMPFile::getData() const
{
    return Data;
}

const BMP &BMPFile::getHeader() const
{
    return header;
}
