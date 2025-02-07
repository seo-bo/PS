#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int,string>m1;
    map<string,int>m2;
    for(int i =0; i<players.size();++i)
    {
        m1[i] = players[i];
        m2[players[i]] = i;
    }
    for(auto & i : callings)
    {
        auto it = m2.find(i);
        int pivot = it->second;
        auto jt = m1.find(pivot - 1);
        string name = jt->second;
        m1.erase(pivot-1);
        m1.erase(pivot);
        m2.erase(i);
        m2.erase(name);
        m1[pivot-1] = i;
        m2[i] = pivot-1;
        m1[pivot] = name;
        m2[name] = pivot;
    }
    for(auto & [a,b] : m1)
    {
        answer.push_back(b);
    }
    return answer;
}