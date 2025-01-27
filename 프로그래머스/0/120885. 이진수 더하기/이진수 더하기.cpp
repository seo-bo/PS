#include <bits/stdc++.h>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int a = 0;
    for(int i =(int)bin1.size()-1, cnt = 0; i>=0;--i,cnt++)
    {
        if(bin1[i] == '1')
        {
            a += (1<<cnt);
        }
    }
    for(int i =(int)bin2.size()-1,cnt = 0; i>=0;--i,cnt++)
    {
        if(bin2[i] == '1')
        {
            a += (1<<cnt);
        }
    }
    while(a > 0)
    {
        if(a & 1)
        {
            answer += '1';
        }
        else
        {
            answer += '0';
        }
        a >>= 1;
    }
    if(answer.empty())
    {
        return "0";
    }
    reverse(answer.begin(),answer.end());
    return answer;
}