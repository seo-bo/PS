#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll result = 0;
	int N = 0;
	cin >> N;
	vector<vector<int>> v(N + 1);
	for (int i = 0; i < N; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) // 색깔이 두개만 있는게 아닌가..?
	{
		if (v[i].size() > 1)
		{
			sort(v[i].begin(), v[i].end());
			for (int k = 0; k < v[i].size(); ++k)
			{
				if (k == 0)
				{
					result += llabs(v[i][0] - v[i][1]);
				}
				else if (k == v[i].size() - 1)
				{
					result += llabs(v[i][v[i].size() - 1] - v[i][v[i].size() - 2]);
				}
				else
				{
					result += min(llabs(v[i][k] - v[i][k - 1]), llabs(v[i][k] - v[i][k + 1]));
				}
			}
		}
	}
	cout << result;
	return 0;
}