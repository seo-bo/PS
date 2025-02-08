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
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n + 1, vector<int>(6));
	vector<set<int>>s(n + 1);
	for (int i = 1; i <= n; ++i) // 번호
	{
		for (int j = 1; j <= 5; ++j) // 학년
		{
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= 5; ++i) // 학년
	{
		for (int j = 1; j <= n; ++j) // 학생 1 번호
		{
			for (int k = j + 1; k <= n; ++k) // 학생 2 번호
			{
				if (v[j][i] == v[k][i])
				{
					s[j].insert(k);
					s[k].insert(j);
				}
			}
		}
	}
	int ma = s[1].size(), ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (s[i].size() > ma)
		{
			ans = i;
			ma = s[i].size();
		}
	}
	cout << ans;
	return 0;
}