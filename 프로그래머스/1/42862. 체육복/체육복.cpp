#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    set<int>s(reserve.begin(),reserve.end());
    for(auto & i : lost)
    {
        if(s.find(i) != s.end())
        {
            answer++;
            s.erase(i);
            i = -1;
        }
    }
    sort(lost.begin(),lost.end());
    for(auto & i : lost)
    {
        if(i == -1)
        {
            continue;
        }
        if(s.find(i -1) != s.end())
        {
            answer++;
            s.erase(i-1);
        }
        else if(s.find(i+1) != s.end())
        {
            answer++;
            s.erase(i+1);
        }
    }
    return answer;
}