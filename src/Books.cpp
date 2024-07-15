#include <iostream>
#include <string>
#include <cstring>

#include "../includes/Book.hpp"
#include "../includes/Format.hpp"

using namespace std;

Book::Book(string name) : m_name(name), m_description("")
{
}

Book::Book(string name, string description) : m_name(name), m_description(description)
{
}

Book::~Book()
{
}

void Book::display(ostream &stream) const
{
    stream << "- " << m_name;
    if (m_description.empty()) {
        cout << endl;
    } else {
        cout << " : " << endl;
        cout << "\t" << m_description << endl;
    }
}

ostream& operator<<( ostream &stream, Book const& col)
{
    col.display(stream) ;
    return stream;
}


bool Book::matchBookName(std::string str)
{
    Format::strToLower(m_name);
    if (str == m_name) {
        m_name[0] = toupper(m_name[0]);
        return true;
    }
    m_name[0] = toupper(m_name[0]);
    return false;
}

bool Book::matchBookNameNcar(std::string str, int n)
{
    Format::strToLower(m_name);
    if (strncmp(m_name.c_str(), str.c_str(), n) == 0) {
        m_name[0] = toupper(m_name[0]);
        return true;
    }
    m_name[0] = toupper(m_name[0]);
    return false;
}
