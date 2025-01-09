#include <bits/stdc++.h>
#include <unordered_set>
#define INF INT_MIN
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
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<ti>per;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			per.push_back(make_tuple(v[i][j], i, j));
		}
	}
	sort(per.begin(), per.end(), greater<ti>());
	auto check = [&](pii a, pii b)
		{
			return (abs(a.first - b.first) + abs(a.second - b.second)) == 1;
		};
	vector<pii>temp;
	int pivot = min(n * m, 25);
	function<int(int, int)> dfs = [&](int depth, int cnt) -> int // 흠.. 전탐색??
		{
			// 생각해보자... 5개 있고 1000 x 1000 일때? 1개 픽하면 최소 2개, 최대 4개 구간 없어짐(선택 가능한)
			// 그럼 최소 8개, 최대 21개 구간인가? 근데 2개 없앨 수 있는건 모서리 부분밖에 없는거 같으니까 그냥 최대로?
			if (depth == pivot || !cnt) 
			{
				return 0;
			}
			auto [c, nx, ny] = per[depth];
			bool flag = true;
			for (auto& [x, y] : temp)
			{
				if (check(make_pair(x, y), make_pair(nx, ny)))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				temp.push_back(make_pair(nx, ny));
				int a = dfs(depth + 1, cnt - 1) + c;
				temp.pop_back();
				return max(a, dfs(depth + 1, cnt));
			}
			return dfs(depth + 1, cnt);
		};
	cout << dfs(0, k);
	return 0;
}