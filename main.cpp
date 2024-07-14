#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

#include "includes/Collection.hpp"
#include "includes/Format.hpp"


using namespace std;


void displayBookshopHelp()
{
    cout << "List of commands :" << endl;
    cout << "\t- new collection : create a new collection. Name and size are mandatory." << endl;
    cout << "\t- list collection : list all the created collection." << endl;
    cout << "\t- new book : add a new book to bookshop." << endl;
    cout << "\t- exit : exit the bookshop." << endl;
    cout << endl;
}

void displayProgramHelp()
{
    cout << "USAGE :" << endl;
    cout << "\t ./mybookshop" << endl;
    cout << "DESCRIPTION :" << endl;
    cout << "\t- new collection : create a new collection. Name and size are mandatory." << endl;
    cout << "\t- list collection : list all the created collection." << endl;
    cout << "\t- new book : add a new book to bookshop." << endl;
    cout << "\t- exit : exit the bookshop." << endl;
    cout << "\t- help : display help." << endl;
}

void instructionHandler(string instrution, vector<Collection>& allCollection, Bookshop& bs)
{
    if (instrution == "newcollection" or instrution == "nc") {
        newCollection(allCollection);
        return;
    }
    if (instrution == "listcollection" or instrution == "list") {
        cout <<  endl << "Collections :" << endl;
        for (int i = 0; i < allCollection.size(); i++) {
            cout << allCollection[i];
        }
        cout << "The total number of collection is " << allCollection.size() << "." << endl << endl;
        return;
    }
    if (instrution == "newbook" or instrution == "nb") {
        bs.newBook();
        return;
    }
    if (instrution == "help") {
        displayBookshopHelp();
        return;
    }
    cout << "Invalid instruction. Try again." << endl;
}

int main(const int argc, const char *argv[])
{
    Bookshop bs;
    vector<Collection> allCollection(0);
    string instruction("");

    if (argc == 2 and strcmp(argv[1], "-h") == 0) {
        displayProgramHelp();
        return 0;
    }
    cout << "Welcome to our bookshop, feel free to create/manage books and collection." << endl;
    do {
        cout << "Enter an intruction : ";
        getline(cin, instruction);
        Format::removeSpaces(instruction);
        instructionHandler(instruction, allCollection, bs);
    } while (instruction != "exit");
    cout << "Thanks for visiting us. Hope you will be back soon !" << endl;
    return 0;
}