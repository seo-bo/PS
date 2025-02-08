#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int>v;
    stringstream ss(s);
    string str;
    while(ss >> str)
    {
        v.push_back(stoi(str));
    }
    sort(v.begin(),v.end());
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v.back());
    return answer;
}