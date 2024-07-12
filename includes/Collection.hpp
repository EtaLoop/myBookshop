#ifndef COLLECTION
#define COLLECTION

#include <string>

class Collection
{
    public:

    Collection();
    Collection(std::string name, int size);
    void addBook();
    void delBook();
    void displayState() const;
    void changeName(std::string name);
    void changeSize(int size);
    std::string getName() const;
    int getSize() const;

    private:

    std::string m_name;
    int m_size;
    int m_curr_nb_book;
};

#endif
