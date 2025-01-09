#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) 
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<bool>visited(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int a;
		char b;
		cin >> a >> b;
		if (b == 'M' && !visited[a])
		{
			cout << yes << '\n';
			visited[a] = true;
		}
		else
		{
			cout << no << '\n';
		}
	}
	return 0;
}
