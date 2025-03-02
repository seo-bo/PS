#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int>prefix(50,0);
    int n = players.size();
    for(int i =0; i<n;++i)
    {      
        ll a = players[i] / m;
        ll b = max(0LL,a - prefix[i]);
        answer += b;
        prefix[i+1] += prefix[i] + b;
        prefix[i+k] -= b;       
    }
    return answer;
}