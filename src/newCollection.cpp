#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "../includes/bookshop.hpp"

using namespace std;

static int stringIsNum(string str)
{
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < '0' or str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void newCollection(vector<Collection>& allCollection)
{
    Collection col;
    string buff("");
    int size(0);

    cout << "Enter the new collection name : ";
    getline(cin, buff);
    col.changeName(buff);
    cout << "Enter the new collection size : ";
    getline(cin, buff);
    while (!stringIsNum(buff)) {
        cout << "Invalid number. Try again : ";
        getline(cin, buff);
    }
    size = stoi(buff);
    col.changeSize(size);
    allCollection.push_back(col);
    cout << endl << "You successfully created a new collection of " << col.getSize()
    << " books, named \'" << col.getName() << "\'." << endl << endl;
}
