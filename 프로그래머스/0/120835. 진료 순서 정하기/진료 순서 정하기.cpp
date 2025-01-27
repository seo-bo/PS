#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    map<int,int>mm;
    vector<int> t = emergency;
    sort(t.rbegin(),t.rend());
    for(auto & i : t)
    {
        mm[i] = mm.size() + 1;
    }
    for(auto & i : emergency)
    {
        answer.push_back(mm[i]);
    }
    return answer;
}