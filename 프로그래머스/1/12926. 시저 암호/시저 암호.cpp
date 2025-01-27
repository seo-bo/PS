#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(auto & i : s)
    {
        if('a' <= i && i <='z')
        {
            i = (i -'a'+ n) % 26 + 'a';
        }
        else if('A' <= i && i <= 'Z')
        {
             i = (i -'A'+ n) % 26 + 'A';
        }
    }
    return s;
}