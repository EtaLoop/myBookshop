#include <string>
#include <iostream>

#include "../includes/Collection.hpp"
#include "../includes/Format.hpp"

using namespace std;


Bookshop::Bookshop() : m_tot_book(0)
{
}

Bookshop::~Bookshop()
{
    for (int i = 0; i < m_booksList.size(); i++) {
        delete m_booksList[i];
    }
}

void Bookshop::newBook()
{
    string bookName("");
    string bookDesc("");

    cout << "What is the new book name ? : ";
    getline(cin, bookName);
    while (not Format::strIsAlpha(bookName)) {
        cout << "Invalid name. A book name must contain only letters. Try again : ";
        getline(cin, bookName);
    }
    cout << "Would you like to add a description to it ? (Yes or No) : ";
    getline(cin, bookDesc);
    while (bookDesc != "No" and bookDesc != "no" and bookDesc != "N" and bookDesc != "yes" and
    bookDesc != "Y" and bookDesc != "Yes") {
        cout << "Wrong answer. Try again : ";
        getline(cin, bookDesc);
    }
    if (bookDesc == "No" or bookDesc == "no" or bookDesc == "N") {
        m_booksList.push_back(new Book(bookName));
    } else {
        cout << "Enter description : ";
        getline(cin, bookDesc);
        m_booksList.push_back(new Book(bookName, bookDesc));
    }
    cout << endl << "You successfully added \'" << bookName << "\'." << endl << endl;
    m_tot_book += 1;
}

void Bookshop::listBookList()
{
    cout << endl << "List of books :" << endl;
    for (int i = 0; i < m_booksList.size(); i++) {
        cout << (*m_booksList[i]);       
    }
    cout << endl;
    cout << "Total of " << m_booksList.size() << " books." << endl << endl;
}

void Bookshop::searchBook(string to_search)
{
    int book_found = 0;
    
    cout << endl << "To search : " << to_search << endl;
    Format::strToLower(to_search);
    for (int i = 0; i < m_booksList.size(); i++) {
        if (m_booksList[i]->matchBookNameNcar(to_search, to_search.size())) {
            if (book_found == 0) {
                cout << "Books found :" << endl;
            }
            cout << (*m_booksList[i]);
            book_found++;
        }
    }
    if (book_found == 0) {
        cout << "No books founds." << endl << endl;
    } else {
        cout << endl;
    }
}



Collection::Collection() : m_name("Default Collection"), m_size(10), m_curr_nb_book(0)
{
}

Collection::Collection(string name, int size) : m_name(name), m_size(size), m_curr_nb_book(0)
{
}

void Collection::delBook()
{

}

void Collection::changeName(string name)
{
    m_name = name;
}

void Collection::changeSize(int size)
{
    m_size = size;
}

void Collection::display(ostream &stream) const
{
    stream << m_name << " : " << m_curr_nb_book << "/" << m_size << " books" << endl;
}

ostream& operator<<( ostream &stream, Collection const& col)
{
    col.display(stream) ;
    return stream;
}
