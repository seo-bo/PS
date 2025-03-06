#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int>mm;
    map<string,int>ans;
    auto cal = [&] (string a)
    {
        int res = stoll(a.substr(0,2)) * 60;
        res += stoll(a.substr(3,2));
        return res;
    };
    for(auto & i : records)
    {
        stringstream ss(i);
        vector<string>v;
        string str;
        while(ss >> str)
        {
            v.push_back(str);
        }
        if(mm.find(v[1]) == mm.end())
        {
            mm[v[1]] = cal(v[0]);
        }
        else
        {
            int pivot = cal(v[0]);
            ans[v[1]] += (pivot - mm[v[1]]);
            mm.erase(v[1]);
        }
    }
    int pivot = 60 * 23 + 59;
    for(auto & [a,b] : mm)
    {
        ans[a] += (pivot - b);
    }
    for(auto & [a,b] : ans)
    {
        int pp = fees[1] + max(0,(b - fees[0] + fees[2] -1) / fees[2] * fees[3]);
        answer.push_back(pp);
    }
    return answer;
}