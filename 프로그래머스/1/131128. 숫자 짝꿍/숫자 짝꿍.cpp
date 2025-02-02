#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char,int>mm;
    for(auto & i : X)
    {
        mm[i]++;
    }
    for(auto & i : Y)
    {
        if(mm.find(i) != mm.end())
        {
            answer += i;
            if(--mm[i] == 0)
            {
                mm.erase(i);
            }
        }
    }
    if(answer.empty())
    {
        return "-1";
    }
    sort(answer.rbegin(),answer.rend());
    while(answer.size() > 1 && answer[0] == '0')
    {
        answer.erase(answer.begin());
    }
    return answer;
}