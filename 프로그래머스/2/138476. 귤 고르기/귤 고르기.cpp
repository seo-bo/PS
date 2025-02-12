#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,vector<int>>mm;
    map<int,int>m;
    for(auto & i : tangerine)
    {
        m[i]++;
    }
    for(auto & [a,b] : m)
    {
        mm[b].push_back(a);
    }
    for(auto it = mm.rbegin(); it != mm.rend(); ++it)
    {
        for(auto & i : it->second)
        {
            if(k == 0)
            {
                return answer;
            }
            k -= min(k,it->first);
            answer++;
        }
    }
    return answer;
}