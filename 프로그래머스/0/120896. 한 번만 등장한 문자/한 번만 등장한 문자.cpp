#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char,int>mm;
    for(auto & i :s)
    {
        mm[i]++;
    }
    for(auto & [a,b] : mm)
    {
        if(b == 1)
        {
            answer += a;
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}