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
	vector<priority_queue<int>>v(n + 1);
	map<int, int>sc;
	int pivot = -1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp = 0;
			cin >> temp;
			v[i].push(temp);
			pivot = max(pivot,temp);
		}
	}
	int tempp = -1, sca = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int a = v[j].top();
			v[j].pop();
			if (a == pivot)
			{		
				sc[j]++;
			}
			if (!v[j].empty())
			{
				tempp = max(tempp, v[j].top());
			}
			sca = max(sc[j], sca);
		}
		pivot = tempp;
		tempp = -1;
	}
	for (auto& [i, j] : sc)
	{
		if (j == sca)
		{
			cout << i << ' ';
		}
	}
	return 0;
}