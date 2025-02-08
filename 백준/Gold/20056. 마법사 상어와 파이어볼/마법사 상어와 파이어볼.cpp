#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<vector<ti>>>v(n, vector<vector<ti>>(n));
	vector<vector<int>>dir = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	for (int i = 0; i < m; ++i)
	{
		int r = 0, c = 0, m = 0, s = 0, d = 0;
		cin >> r >> c >> m >> s >> d;
		r--, c--;
		v[r][c].push_back(make_tuple(m, s, d)); // 질량, 속도, 방향
	}
	for (int i = 0; i < k; ++i)
	{
		vector<vector<vector<ti>>>temp(n, vector<vector<ti>>(n)); // 임시 공간
		for (int i = 0; i < n; ++i) 
		{
			for (int j = 0; j < n; ++j)
			{
				for (auto& [m, s, d] : v[i][j])
				{
					int nx = i + dir[d][0] * s;
					int ny = j + dir[d][1] * s;
					(nx >= 0) ? nx %= n : nx = (nx % n + n) % n;
					(ny >= 0) ? ny %= n : ny = (ny % n + n) % n;
					temp[nx][ny].push_back(make_tuple(m, s, d));
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (temp[i][j].size() >= 2)
				{
					vector<ti>tt;
					int tm = 0, ts = 0;
					bool even = false, odd = false;
					for (auto& [m, s, d] : temp[i][j])
					{
						tm += m, ts += s;
						if (d % 2)
						{
							odd = true;
						}
						else
						{
							even = true;
						}
					}
					if (tm / 5 > 0)
					{
						int pivot = 0;
						if (odd && even)
						{
							pivot = 1;
						}
						tm /= 5;
						ts /= temp[i][j].size();
						for (int i = pivot; i <= pivot + 6; i += 2)
						{
							tt.push_back(make_tuple(tm, ts, i));
						}
					}
					swap(temp[i][j], tt);
				}
			}
		}
		swap(temp, v);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (auto& [m, s, d] : v[i][j])
			{
				ans += m;
			}
		}
	}
	cout << ans;
	return 0;
}