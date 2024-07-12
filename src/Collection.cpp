#include <string>
#include <iostream>

#include "../includes/Collection.hpp"

using namespace std;


Collection::Collection() : m_name("Default Collection"), m_size(10), m_curr_nb_book(0)
{

}

Collection::Collection(string name, int size) : m_name("Default Collection"),
m_size(10), m_curr_nb_book(0)
{
    m_name = name;
    m_size = size;
}

static int stringIsAlpha(string str)
{
    for (int i = 0; i < str.size(); i++) {
        if (((str[i] < 'A') or (str[i] > 'Z' and str[i] < 'a') or (str[i] > 'z')) and str[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

void Collection::addBook()
{
    string bookName("");

    if (m_curr_nb_book >= m_size) {
        cout << "You cannot add an other book, your Collection is full." << endl;
        return;
    }
    cout << "What is the new book name ?" << endl;
    getline(cin, bookName);
    while (!stringIsAlpha(bookName)) {
        cout << "Invalid name. A book name must contain only letters. Try again :" << endl;
        getline(cin, bookName);
    }
    cout << "You successfully added \'" << bookName << "\'" << endl;
    m_curr_nb_book += 1;
}

void Collection::delBook()
{

}

void Collection::displayState() const
{
    cout << "The collection \'" << m_name << "\' has a total of " <<
    m_curr_nb_book << " registered books out of " << m_size << " books." << endl;
}

void Collection::changeName(string name)
{
    m_name = name;
}

void Collection::changeSize(int size)
{
    m_size = size;
}


string Collection::getName() const
{
    return m_name;
}

int Collection::getSize() const
{
    return m_size;
}

