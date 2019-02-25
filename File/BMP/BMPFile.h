//
// Created by bear on 25.02.19.
//

#ifndef UNTITLED2_BMPFILE_H
#define UNTITLED2_BMPFILE_H

#include <cstdio>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "../File.h"
#include "../Input/FileBinaryInput.h"

#define FILE_SUCCESSFUL 0
#define FILE_DIDNOTOPEN 1
#define FILE_IO 2
#define FILE_NOTBMP 3
#define _FILE_UNKNOWN 4
#define FILE_MEMORYDIDNTALLOC 5
#define FILE_NOTSUPPORT 6

using namespace std;

struct ColorMap
{
    char Blue;
    char Green;
    char Red;
    char Reserved;
};
#pragma pack(push)
#pragma pack(1)
struct BMP//Структура BMP файла
{
    uint16_t Signature;
    int Filesize;
    int Reserved;
    int Offset;
    int Structsize;
    int Width;
    int Height;
    uint16_t Planecount;
    uint16_t Bitcount;
    int Compression;
    int ImageSize;
    int Xpixels;
    int Ypixels;
    int Colorcount;
    int Importantcolor;
};
#pragma pack(pop)

class BMPFile : public File
{
private:
    vector<char> Data;
    BMP header;
public:
    BMPFile(const string &name);
    void set(const char *name);
    void set(const string &name);
    int load();
    const vector<char> &getData() const;

    const BMP &getHeader() const;
};


#endif //UNTITLED2_BMPFILE_H
