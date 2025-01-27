#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(auto & i :str)
    {
        if('a' <= i && i <= 'z')
        {
            i = toupper(i);
        }
        else if('A' <= i && i <= 'Z')
        {
            i = tolower(i);
        }
    }
    cout << str;
    return 0;
}