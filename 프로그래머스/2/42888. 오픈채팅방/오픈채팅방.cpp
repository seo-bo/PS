#include <bits/stdc++.h>

using namespace std;
typedef pair<string,int>pii;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    int n = record.size();
    vector<pii>ok;
    map<string,string>mm;
    for(auto & i : record)
    {
        stringstream ss(i);
        string str;
        vector<string>v;
        while(ss >> str)
        {
            v.push_back(str);
        }
        if(v[0] == "Enter" || v[0] == "Change")
        {
            mm[v[1]] = v[2];
            if(v[0] == "Enter")
            {
                ok.push_back(make_pair(v[1],1));
            }
        }
        else
        {
            ok.push_back(make_pair(v[1],0));
        }
    }
    for(auto & [a,b] : ok)
    {
        string temp = "";
        temp += mm[a];
        if(b)
        {   
            temp += "님이 들어왔습니다."; 
        }
        else
        {
            temp += "님이 나갔습니다."; 
        }
        answer.push_back(temp);
    }
    return answer;
}