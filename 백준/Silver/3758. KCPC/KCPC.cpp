#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tp;
typedef tuple<int, int, int, int> tpp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, k = 0, t = 0, m = 0;
		cin >> n >> k >> t >> m;
		vector<vector<tp>>v(n + 1, vector<tp>(k + 1, make_tuple(0, 0, 0))); // 점수, 제출 횟수, 마지막 제출 시간
		for (int i = 1; i <= m; ++i)
		{
			int pa = 0, pb = 0, pc = 0;
			cin >> pa >> pb >> pc;
			auto& [a, b, c] = v[pa][pb];
			a = max(a, pc);
			b++;
			c = i;
		}
		vector<tpp>ans;
		for (int i = 1; i <= n; ++i)
		{
			int score = 0, sub = 0, last = 0;
			for (int j = 1; j <= k; ++j)
			{
				auto [a, b, c] = v[i][j];
				score += a;
				sub += b;
				last = max(last, c);
			}
			ans.push_back(make_tuple(score, sub, last, i));
		}
		sort(ans.begin(), ans.end(), [&](const tpp& a, const tpp& b)
			{
				if (get<0>(a) == get<0>(b))
				{
					if (get<1>(a) == get<1>(b))
					{
						return get<2>(a) < get<2>(b);
					}
					return get<1>(a) < get<1>(b);
				}
				return get<0>(a) > get<0>(b);
			});
		for (int i = 0; i < n; ++i)
		{
			if (get<3>(ans[i]) == t)
			{
				cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}