#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<ll,ll>mm;
    for(auto & i : weights)
    {
        mm[i]++;
    }
    for(auto & [a,b] : mm)
    {
        answer += b * (b-1);
        for(int i =2; i<=4;++i)
        {
            ll pivot = a * i;
            for(int j =2; j<=4;++j)
            {
                if(pivot % j || i == j)
                {
                    continue;
                }
                ll ok = pivot / j;
                if(mm.find(ok) != mm.end())
                {
                    answer += mm[ok] * b;
                }
            }
        }
    }
    return answer / 2;
}