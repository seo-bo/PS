#include<bits/stdc++.h>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    stringstream ss(binomial);
    string str;
    vector<string>v;
    while(ss >> str)
    {
        v.push_back(str);
    }
    if(v[1] == "+")
    {
        return stoi(v[0]) + stoi(v[2]);
    }
    else if(v[1] == "-")
    {
        return stoi(v[0]) - stoi(v[2]);
    }
    else
    {
        return stoi(v[0]) * stoi(v[2]);
    }
    return answer;
}