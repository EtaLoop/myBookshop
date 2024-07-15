#ifndef DEF_BOOK
#define DEF_BOOK

#include <string>

class Book
{
public:
    Book(std::string name);
    Book(std::string name, std::string description);
    ~Book();
    void display(std::ostream &stream) const;
    bool matchBookName(std::string str);
    bool matchBookNameNcar(std::string str, int n);

protected:

    friend std::ostream &operator<<(std::ostream &stream, Book const &book);

    std::string m_name;
    std::string m_description;
};


#endif
