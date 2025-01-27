#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(auto & i :str)
    {
        cout << i << '\n';
    }
    return 0;
}