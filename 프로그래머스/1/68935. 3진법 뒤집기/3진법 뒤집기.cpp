#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str;
    while(n > 0)
    {
        str += to_string(n % 3);
        n /=3;
    }
    int cnt = 0;
    for(int i = (int)str.size() -1; i>=0;--i)
    {
        answer = answer + ((int)pow(3,cnt++)) * (str[i] - '0');
    }
    return answer;
}