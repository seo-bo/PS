#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n;
	vector<ll>prefix(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		end++;
		cout << prefix[end] - prefix[start] << "\n";
	}
	return 0;
}