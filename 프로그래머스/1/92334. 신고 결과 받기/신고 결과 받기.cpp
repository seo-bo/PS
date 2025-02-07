#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string>pss;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    vector<int> answer(n);
    set<pss>s;
    map<int,string>ok;
    map<string,int>ban;
    for(int i =0; i<n;++i)
    {
        ok[i] = id_list[i];
    }
    map<string,vector<string>>graph;
    for(auto & i : report)
    {
        stringstream ss(i);
        string str;
        vector<string>v;
        while(ss >> str)
        {
            v.push_back(str);
        }
        if(s.find(make_pair(v[0],v[1])) != s.end())
        {
            continue;
        }
        s.insert(make_pair(v[0],v[1]));
        graph[v[0]].push_back(v[1]);
        ban[v[1]]++;
    }
    for(int i =0; i<n;++i)
    {
        string str = ok[i];
        for(auto j : graph[str])
        {
            if(ban[j] >= k)
            {
                answer[i]++;
            }
        }
    }
    return answer;
}