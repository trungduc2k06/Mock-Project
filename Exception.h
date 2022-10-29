#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include "Library.h"

class NameException : public exception
{
    public:
        string what()
        {
            return "Invalid name!";
        }
};

#endif 