#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
    set<int>s;
    for(int i =2; i<=n;++i)
    {
        while(n % i == 0)
        {
            s.insert(i);
            n /= i;
        }
    }
    vector<int>answer(s.begin(),s.end());
    return answer;
}