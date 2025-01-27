#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    int pre = 0;
    stringstream ss(s);
    string str;
    while(ss >> str)
    {
        if(str == "Z")
        {
            answer -= pre;
            pre = 0;
        }
        else
        {
            answer += stoi(str);
            pre = stoi(str);
        }
    }
    return answer;
}