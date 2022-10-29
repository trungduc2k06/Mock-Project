#include "Validation.h"

bool is_character(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    return false;
}
bool is_number(char ch)
{
    if(ch >= '0' && ch <='9')
    {
        return true;
    }
    return false;
}

bool checkName(string name)
{
    try
    {
        for(int i = 0; i < name.length(); i++)
        {
            if(!is_character(name[i]))
            {
                if(name[i] == ' ')
                {
                    throw NameException();
                }
            }
        }
    }
    catch(NameException& ex)
    {
        cout << ex.what() << endl;
        return false;
    }
    return true;
}

