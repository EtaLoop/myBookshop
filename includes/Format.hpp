#ifndef DEF_FORMAT
#define DEF_FORMAT

#include <string>

class Format
{
public:
    Format();
    ~Format();
    static bool strIsAlpha(std::string str);
    static void removeSpaces(std::string& str);
};


#endif
