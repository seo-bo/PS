#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    deque<char>a;
    deque<char>b;
    for(auto &i  : pat)
    {
        b.push_back(i);
    }
    int n = pat.size();
    int idx = 0;
    while(idx < (int)myString.size())
    {
        if(!a.empty())
        {
            a.pop_front();
        }
        while(idx < (int)myString.size() && a.size() < b.size())
        {
            a.push_back(myString[idx++]);
        }
        if(a == b)
        {
            answer++;
        }
    }
    return answer;
}