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
	int r = 0, c = 0, k = 0;
	cin >> r >> c >> k;
	--r, --c;
	vector<deque<int>>v;
	for (int i = 0; i < 3; ++i)
	{
		deque<int>temp;
		for (int j = 0; j < 3; ++j)
		{
			int t = 0;
			cin >> t;
			temp.push_back(t);
		}
		v.push_back(temp);
	}
	int row = 3, col = 3;
	auto sv = [&](int row, int col)
		{
			int pivot = 0;
			vector<deque<int>>ans(row);
			for (int i = 0; i < row; ++i)
			{
				unordered_map<int, int>mm;
				for (int j = 0; j < col && j < 100; ++j)
				{
					if (v[i][j])
					{
						mm[v[i][j]]++;
					}
				}
				vector<pii>a(mm.begin(), mm.end());
				sort(a.begin(), a.end(), [&](const pii& A, const pii& B)
					{
						if (A.second == B.second)
						{
							return A.first < B.first;
						}
						return A.second < B.second;
					});
				int cnt = 0;
				for (auto& [c, d] : a)
				{
					if (cnt > 100)
					{
						break;
					}
					ans[i].push_back(c), ans[i].push_back(d);
					cnt += 2;
				}
				pivot = max(min(100, pivot), (int)ans[i].size());
			}
			for (auto& i : ans)
			{
				while (i.size() < 100 && i.size() < pivot)
				{
					i.push_back(0);
				}
			}
			v = ans;
			return pivot;
		};
	auto swp = [&](int row, int col)
		{
			vector<deque<int>>ans(col);
			for (int i = 0; i < col; ++i)
			{
				for (int j = 0; j < row; ++j)
				{
					ans[i].push_back(v[j][i]);
				}
			}
			v = ans;
		};
	for (int _ = 0; _ <= 100; ++_)
	{
		if (r < row && c < col && v[r][c] == k)
		{
			cout << _ << '\n';
			return 0;
		}
		if (row >= col) // r 연산
		{
			col = sv(row, col);
		}
		else // c 연산
		{
			swp(row, col);
			row = sv(col, row);
			swp(col, row);
		}
	}
	cout << -1 << '\n';
	return 0;
}