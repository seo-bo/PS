#include <bits/stdc++.h>

using namespace std;

string solution(string rsp) {
    string answer = "";
    map<char,char>m = {{'2','0'},{'0','5'},{'5','2'}};
    for(auto & i :rsp)
    {
        answer += m[i];
    }
    return answer;
}