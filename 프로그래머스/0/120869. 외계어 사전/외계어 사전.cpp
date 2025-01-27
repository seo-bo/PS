#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    string str;
    for(auto & i : spell)
    {
        str += i[0];
    }
    sort(str.begin(),str.end());
    for(auto & i : dic)
    {
        sort(i.begin(),i.end());
        if(str == i)
        {
            return 1;
        }
    }
    return answer;
}