#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "../includes/Format.hpp"

using namespace std;

Format::Format()
{
}

Format::~Format()
{
}

bool Format::strIsAlpha(string str)
{
    if (str.size() == 0) {
        return false;
    }
    for (int i = 0; i < str.size(); i++) {
        if (not (isalpha(str[i])) and str[i] != ' ') {
            return false;
        }
    }
    return true;
}

void Format::removeSpaces(string& str)
{
    auto end = remove(str.begin(), str.end(), ' ');

    str.erase(end, str.end());
}

void Format::strToLower(string& str)
{
    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
}

