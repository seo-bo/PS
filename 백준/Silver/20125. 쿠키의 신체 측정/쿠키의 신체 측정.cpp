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
	int n = 0;
	cin >> n;
	vector<int>ans(5);
	int x = -1, y = -1;
	vector<vector<char>>v(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		for (int j = 0; j < n; ++j)
		{
			v[i][j] = a[j];
		}
	}
	auto t = [&]
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (v[i][j] == '*' && v[i + 1][j] == '*')
					{
						x = i + 1, y = j;
						return;
					}
				}
			}
		};
	t();
	auto cal = [&]
		{
			int nx = x, ny = y - 1;
			while (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] == '*')
			{
				ans[0]++;
				ny--;
			}
			nx = x, ny = y + 1;
			while (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] == '*')
			{
				ans[1]++;
				ny++;
			}
			nx = x + 1, ny = y;
			while (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] == '*')
			{
				ans[2]++;
				nx++;
			}
			int px = nx, py = ny;
			nx = px, ny = py - 1;	
			while (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] == '*')
			{
				ans[3]++;
				nx++;
			}	
			nx = px, ny = py + 1;
			while (nx >= 0 && nx < n && ny >= 0 && ny < n && v[nx][ny] == '*')
			{
				ans[4]++;
				nx++;
			}
		};
	cal();
	cout << x + 1 << ' ' << y + 1 << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}