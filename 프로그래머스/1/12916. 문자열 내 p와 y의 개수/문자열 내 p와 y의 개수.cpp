#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int a = 0, b = 0;
    for(auto & i : s)
    {
        if(tolower(i) == 'p')
        {
            a++;
        }
        else if(tolower(i) == 'y')
        {
            b++;
        }
    }
    return (a==b);
}