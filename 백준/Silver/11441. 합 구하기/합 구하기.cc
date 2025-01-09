#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<ll>prefix(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	int query = 0;
	cin >> query;
	while (query--)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		cout << prefix[end] - prefix[start - 1] << '\n';
	}
	return 0;
}