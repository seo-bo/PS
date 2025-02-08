#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<int, int, int, int>tti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, K = 0;
	cin >> n >> m >> K;
	vector<ti>shark(m + 1); // 좌표, 방향
	vector<vector<vector<int>>>sdir(m + 1, vector<vector<int>>(4));
	vector<vector<pii>>v(n, vector<pii>(n, make_pair(-1, -1)));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j].first;
			if (v[i][j].first)
			{
				shark[v[i][j].first] = make_tuple(i, j, 0);
				v[i][j].second = K;
			}
			else
			{
				v[i][j].first = -1;
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		int temp = 0;
		cin >> temp;
		auto& [a, b, c] = shark[i];
		c = --temp;
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				int temp = 0;
				cin >> temp;
				sdir[i][j].push_back(--temp);
			}
		}
	}
	auto rv = [&]
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					auto& [a, b] = v[i][j];
					if (a > 0 && !(--b))
					{
						v[i][j] = make_pair(-1, -1);
					}
				}
			}
		};
	auto move = [&]
		{
			vector<vector<pii>>temp = v;
			for (int i = 1; i <= m; ++i)
			{
				auto [x, y, _] = shark[i];
				if (x == -1)
				{
					continue;
				}
				tti pivot = make_tuple(-1, -1, -1, 0); // fourth는 빈칸인지 아닌지
				for (auto& k : sdir[i][_])
				{
					int nx = x + dir[k][0];
					int ny = y + dir[k][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						if (v[nx][ny].first == -1)
						{
							pivot = make_tuple(nx, ny, k, 1);
							break;
						}
						else if (v[nx][ny].first == i && pivot == make_tuple(-1, -1, -1, 0))
						{
							pivot = make_tuple(nx, ny, k, 0);
						}
					}
				}
				auto [a, b, c, d] = pivot;
				if (a == -1 && b == -1) // 갈곳 못정함
				{
					a = x, b = y, c = _;
				}
				if (temp[a][b].second == K + 1)
				{
					shark[i] = make_tuple(-1, -1, -1);
				}
				else
				{
					temp[a][b] = make_pair(i, K + 1);
					shark[i] = make_tuple(a, b, c);
				}
			}
			v = temp;
			rv();
		};
	for (int i = 1;; ++i)
	{
		if (i == 1001)
		{
			cout << -1;
			break;
		}
		move();
		int cnt = 0;
		for (int j = 1; j <= m; ++j)
		{
			auto [a, b, c] = shark[j];
			if (a == -1)
			{
				continue;
			}
			cnt++;
		}
		if (cnt == 1)
		{
			cout << i;
			break;
		}
	}
	return 0;
}