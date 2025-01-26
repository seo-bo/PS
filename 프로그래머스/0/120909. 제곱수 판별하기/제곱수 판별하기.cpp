#include<bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 1, p = sqrt(n);
    if(p * p != n)
    {
        answer = 2;
    }
    return answer;
}