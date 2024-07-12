#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "includes/bookshop.hpp"

using namespace std;


string formatBuffer(string instruction)
{
    auto end = remove(instruction.begin(), instruction.end(), ' ');

    instruction.erase(end, instruction.end());
    return instruction;
}

void instructionHandler(string instrution, vector<Collection>& allCollection)
{
    if (instrution == "newcollection" or instrution == "new") {
        newCollection(allCollection);
        return;
    }
    if (instrution == "listcollection" or instrution == "list") {
        cout << endl;
        for (int i = 0; i < allCollection.size(); i++) {
            allCollection[i].displayState();
        }
        cout << "The total number of collection is " << allCollection.size() << "." << endl << endl;
    }
}

int main()
{
    vector<Collection> allCollection(0);
    string instruction("");

    do {
        cout << "Enter an intruction : ";
        getline(cin, instruction);
        instruction = formatBuffer(instruction);
        instructionHandler(instruction, allCollection);
    } while (instruction != "exit");
    cout << "Thanks for visiting us. Hope you will be back soon !" << endl;
    return 0;
}