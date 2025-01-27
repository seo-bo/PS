#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(auto & i : quiz)
    {
        stringstream ss(i);
        string temp;
        vector<string>v; 
        while (ss >> temp)
        {
            v.push_back(temp);
        }
        int a = stoi(v[0]), b = stoi(v[2]), c = stoi(v[4]);
        if(v[1] == "+")
        {
            if(a + b == c)
            {
                answer.push_back("O");
                continue;
            }
            answer.push_back("X");
        }
        else
        {
            if(a - b == c)
            {
                answer.push_back("O");
                continue;
            }
            answer.push_back("X");
        }
    }
    return answer;
}