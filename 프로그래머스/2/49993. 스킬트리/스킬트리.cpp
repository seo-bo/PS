#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0, cnt = 1;
    map<char,int>mm;
    for(auto & i :skill)
    {
        mm[i] = cnt++;
    }
    for(auto & i : skill_trees)
    {
        int pre = 0;
        bool flag = true;
        for(auto & j : i)
        {
            if(mm.find(j) != mm.end())
            {
                if(mm[j] == pre + 1)
                {
                    pre++;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            answer++;
        }
    }
    return answer;
}