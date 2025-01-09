#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
unordered_set<ll>mm;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N = 0;
    ll K = 0;
    cin >> N >> K;
    ll sum = (K * (K + 1) / 2);
    while(N--)
    {
        ll temp = 0;
        cin >> temp;
        if (temp <= K && mm.find(temp) == mm.end())
        {
            sum -= temp;
            mm.insert(temp);
        }
    }
    cout << sum << "\n";

    return 0;
}
