#include <string>
#include <algorithm>
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
        if (((str[i] < 'A') or (str[i] > 'Z' and str[i] < 'a') or (str[i] > 'z')) and str[i] != ' ') {
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

