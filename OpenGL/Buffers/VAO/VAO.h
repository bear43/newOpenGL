//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_VAO_H
#define UNTITLED2_VAO_H

#include "../Buffer.h"

class VAO : Buffer
{
public:
    VAO(const string &name);
    void bindBuffer() override;
    static void unbindBuffer();
};


#endif //UNTITLED2_VAO_H