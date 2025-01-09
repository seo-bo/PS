#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, cnt = 0, ans = INT_MAX;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<tuple<int, int, int>>A;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] && v[i][j] != 6)
			{
				A.push_back(make_tuple(i, j, v[i][j]));
			}
			else if (!v[i][j])
			{
				cnt++;
			}
		}
	}
	sort(A.begin(), A.end(), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b)
		{
			return get<2>(a) < get<2>(b);
		});
	vector<vector<int>>dir = { {-1,0},{0,1},{1,0},{0,-1} };
	vector<vector<vector<int>>>dd = { {}, { {0},{1},{2},{3} }, {{0,2},{1,3}}, {{0,1},{1,2},{2,3},{3,0}},{{3,0,1},{0,1,2},{1,2,3},{2,3,0}}, {{0,1,2,3}} };
	auto move = [&](int e, tuple<int, int, int> tp, vector<vector<int>>& temp)
		{
			int cnt = 0;
			auto [x, y, c] = tp;
			for (auto& i : dd[c][e])
			{
				int nx = x, ny = y;
				while (1)
				{
					nx = nx + dir[i][0];
					ny = ny + dir[i][1];
					if (!(nx >= 0 && nx < n && ny >= 0 && ny < m) || temp[nx][ny] == 6)
					{
						break;
					}
					if (!temp[nx][ny])
					{
						temp[nx][ny] = 7;
						cnt++;
					}
				}
			}
			return cnt;
		};
	int depth = A.size();
	function<void(int, int, vector<vector<int>>)> dfs = [&](int start, int sum, vector<vector<int>>vt) ->void
		{
			if (start == depth)
			{
				ans = min(ans, sum);
				return;
			}
			int siz = dd[get<2>(A[start])].size();
			for (int i = 0; i < siz; ++i)
			{
				vector<vector<int>>temp = vt;
				int cnt = move(i, A[start], temp);
				dfs(start + 1, sum - cnt, temp);
			}
		};
	dfs(0, cnt, v);
	cout << ans;
	return 0;
}