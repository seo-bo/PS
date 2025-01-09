#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, v = 0;
	cin >> n >> m >> v;
	vector<int>nocycle(v - 1);
	vector<int>cycle(n - v + 1);
	for (auto& i : nocycle)
	{
		cin >> i;
	}
	for (auto& i : cycle)
	{
		cin >> i;
	}
	int pivot = n - v + 1;
	while (m--)
	{
		int k = 0;
		cin >> k;
		if (k < v - 1)
		{
			cout << nocycle[k] << '\n';
		}
		else
		{
			k -= v - 1;
			k %= pivot;
			cout << cycle[k] << '\n';
		}
	}
	return 0;
}