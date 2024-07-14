#ifndef DEF_BOOK
#define DEF_BOOK

#include <string>

class Book
{
public:
    Book(std::string name);
    Book(std::string name, std::string description);
    ~Book();
private:
    std::string m_name;
    std::string m_description;
};


#endif
