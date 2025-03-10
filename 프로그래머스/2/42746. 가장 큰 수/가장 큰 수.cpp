#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for(auto & i : numbers)
    {
        str.push_back(to_string(i)); 
    }
    sort(str.begin(),str.end(), [&] (const string & a, const string & b)
         {
             string A = a + b;
             string B = b + a;
             return A > B;
         });
    for(auto & i : str)
    {
        answer += i;
    }
    if(answer.front() == '0')
    {
        return "0";
    }
    return answer;
}