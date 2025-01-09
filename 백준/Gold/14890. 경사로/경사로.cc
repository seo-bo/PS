#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, l = 0;
	cin >> n >> l;
	vector<vector<int>>temp(n, vector<int>(n, 0));
	vector<vector<int>>v;
	for (int i = 0; i < n; ++i)
	{
		vector<int>tt;
		for (int j = 0; j < n; ++j)
		{
			cin >> temp[i][j];
			tt.push_back(temp[i][j]);
		}
		v.push_back(tt);
	}
	for (int i = 0; i < n; ++i)
	{
		vector<int>tt;
		for (int j = 0; j < n; ++j)
		{
			tt.push_back(temp[j][i]);
		}
		v.push_back(tt);
	}
	auto check1 = [&](vector<bool>& used, int r, int st) // 낮은곳에서 높은곳으로
		{
			vector<bool>ut = used;
			if (st - l < 0)
			{
				return false;
			}
			int pivot = v[r][st - 1];
			for (int k = st - 1; k >= st - l; --k)
			{
				if (ut[k] || pivot != v[r][k])
				{
					return false;
				}
				ut[k] = true;
			}
			used = ut;
			return true;
		};
	auto check2 = [&](vector<bool>& used, int r, int st) // 높은곳에서 낮은곳으로
		{
			vector<bool>ut = used;
			if (st + l - 1 >= n)
			{
				return false;
			}
			int pivot = v[r][st];
			for (int k = st; k <= st + l - 1; ++k)
			{
				if (ut[k] || pivot != v[r][k])
				{
					return false;
				}
				ut[k] = true;
			}
			used = ut;
			return true;
		};
	int ans = 0;
	for (int i = 0; i < 2 * n; ++i)
	{
		bool flag = true;
		int pre = v[i][0];
		vector<bool>visited(n, false);
		for (int j = 0; j < n; ++j)
		{
			if (pre < v[i][j])
			{
				if (abs(pre - v[i][j]) != 1 || !check1(visited, i, j))
				{
					flag = false;
					break;
				}
			}
			else if (pre > v[i][j])
			{
				if (abs(pre - v[i][j]) != 1 || !check2(visited, i, j))
				{
					flag = false;
					break;
				}
			}
			pre = v[i][j];
		}
		if (flag)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}