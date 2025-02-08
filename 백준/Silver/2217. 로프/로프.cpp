#include <bits/stdc++.h>
#include <unordered_map>
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N = 0, W = 0;
	cin >> N;
	vector<ll>v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i)
	{
		W = max(W, v[i] * (N - i));
	}
	cout << W;
	return 0;
}
