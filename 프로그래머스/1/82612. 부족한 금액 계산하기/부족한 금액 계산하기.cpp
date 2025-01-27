#include<bits/stdc++.h>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0, pivot = price;
    for(int i =1; i<=count;++i)
    {
        answer += pivot;
        pivot += price;
    }
    long long a = max(0LL,answer - money);
    return llabs(a);
}