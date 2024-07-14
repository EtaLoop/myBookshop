#include <iostream>
#include <string>

#include "../includes/Book.hpp"

using namespace std;

Book::Book(string name) : m_name(name)
{
}

Book::Book(string name, string description) : m_name(name), m_description(description)
{
}

Book::~Book()
{
}
