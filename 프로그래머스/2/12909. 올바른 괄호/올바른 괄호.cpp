#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string str)
{
    bool answer = true;
    vector<char>s;
    for(auto & i : str)
    {
        if (i == '(')
        {
            s.push_back(i);
        }
        else
        {
            if(!s.empty())
            {
                s.pop_back();
            }
            else
            {
                s.push_back(i);
            }
        }
    }
    return s.empty();
}