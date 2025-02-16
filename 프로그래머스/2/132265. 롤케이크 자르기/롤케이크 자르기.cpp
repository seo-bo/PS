#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int solution(vector<int> topping) {
    int answer = 0;
    map<int,int>mm;
    for(auto & i : topping)
    {
        mm[i]++;
    }
    map<int,int>p;
    for(auto & i : topping)
    {
        p[i]++;
        if(--mm[i] == 0)
        {
            mm.erase(i);
        }
        if(mm.size() == p.size())
        {
            answer++;
        }
    }
    return answer;
}