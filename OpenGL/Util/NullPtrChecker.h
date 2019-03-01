//
// Created by bear on 28.02.19.
//

#ifndef UNTITLED2_NULLPTTCHECKER_H
#define UNTITLED2_NULLPTTCHECKER_H


namespace NullPtrChecker
{
    inline bool isNullPtr(void* pointer)
    {
        return pointer == nullptr;
    }
    template <class T>
    inline void _delete(T **pointer)
    {
        if(!isNullPtr(*pointer))
        {
            delete *pointer;
        }
        pointer = nullptr;
    }
};


#endif //UNTITLED2_NULLPTTCHECKER_H
