#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int>mm;
    vector<int>o;
    string temp;
    for(auto & i : today)
    {
        if(i == '.')
        {
            o.push_back(stoi(temp));
            temp = "";
            continue;
        }
        temp += i;
    }
    o.push_back(stoi(temp));
    temp = "";
    long long ans = o[0] * 28 * 12 + o[1] * 28 + o[2];  
    for(auto & i : terms)
    {
        stringstream ss(i);
        string str;
        vector<string>ok;
        while(ss >> str)
        {
            ok.push_back(str);
        }
        mm[ok[0][0]] = stoi(ok[1]) * 28;
    }
    int len = privacies.size();
    for(int _ = 0; _ <len;++_)
    {
        auto i = privacies[_];
        int pivot = mm[i.back()];
        vector<int>n;
        for(auto & j : i)
        {
            if(j == ' ')
            {
                break;
            }
            if(j == '.')
            {
                n.push_back(stoi(temp));
                temp = "";
                continue;
            }
            temp += j;
        }
        n.push_back(stoi(temp));
        temp = "";
        long long res = n[0] * 28 * 12 + n[1] * 28 + n[2] + pivot; 
        if(ans >= res)
        {
            answer.push_back(_ + 1);
        }
    }
    return answer;
}