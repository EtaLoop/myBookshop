#ifndef DEF_COLLECTION
#define DEF_COLLECTION

#include <string>
#include <ostream>
#include <vector>
#include "Book.hpp"

class Bookshop
{
public:
    Bookshop();
    ~Bookshop();

    void newBook();
private:
    std::vector<Book*> m_booksList;
    int m_tot_book;
};

class Collection
{
public:
    Collection();
    Collection(std::string name, int size);
    void delBook();
    void changeName(std::string name);
    void changeSize(int size);
    void display(std::ostream &stream) const;

protected:

    friend std::ostream &operator<<(std::ostream &stream, Collection const &col);

    std::string m_name;
    int m_size;
    int m_curr_nb_book;
};

void newCollection(std::vector<Collection>& allCollection);

#endif
