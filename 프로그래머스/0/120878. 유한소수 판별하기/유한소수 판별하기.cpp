#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b) 
{
    int answer = 2;
    int g = gcd(a,b);
    a /= g, b /= g;
    vector<int>v = {2,5};
    for(auto & i : v)
    {
        while(b > 1 && b % i == 0)
        {
            b /=i;
        }
    }
    if(b == 1)
    {
        return 1;
    }
    return answer;
}