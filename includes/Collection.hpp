#ifndef COLLECTION
#define COLLECTION

#include <string>
#include <ostream>

class Collection
{
    public:

    Collection();
    Collection(std::string name, int size);
    void addBook();
    void delBook();
    void changeName(std::string name);
    void changeSize(int size);
    void display(std::ostream &stream) const;

    private:

    std::string m_name;
    int m_size;
    int m_curr_nb_book;
};


std::ostream& operator<<( std::ostream &stream, Collection const& col);

#endif
