#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n)
    {
        if(n%3)
        {
            answer += char(n%3 + '0');
            n /= 3;
        }
        else
        {
            answer += '4';
            n /= 3;
            n--;
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}