#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

// (n-k)!^-1 *(k)! ^ -1 % MOD

ll power (ll base) // a ^ b 빨리 구하는 방법 <- a ^(mod-2)
{
  ll result = 1, exp = MOD -2;
  while(exp > 0)
  {
    if(exp % 2 == 1)
    {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    exp /= 2;
  }
  return result;
}
  
int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  ll n = 0, k = 0;
  cin >> n >> k;
  vector<ll>fact(n+1,1);
  for(ll i = 1; i<=n;++i)
  {
    fact[i] = (fact[i-1] * i) % MOD;
  }
  ll pivot = power(fact[n-k]) * power(fact[k]) % MOD;
  ll ans = fact[n] * pivot % MOD;
  cout << ans;
  return 0;
}
