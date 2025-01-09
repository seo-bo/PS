#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 이게 정해일지도?..
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<ll>prefix(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		prefix[i] = prefix[i - 1] ^ temp;
	}
	ll result = 0;
	while (q--)
	{
		int s = 0, e = 0;
		cin >> s >> e;
		result ^= prefix[e] ^ prefix[s - 1];
	}
	cout << result;
	return 0;
}