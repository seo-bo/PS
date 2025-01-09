#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N =0, K = 1;
	cin >> N;
	while(K < N)
	{
		K = K*2+1;
	}
	if(K != N)
	{
		cout << 2 << "\n" << (K^N) << "\n" << N;
	}
	else
	{
		cout << 1 << "\n" << N;
	}
	return 0;
}

