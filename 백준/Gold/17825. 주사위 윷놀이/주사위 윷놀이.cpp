#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	vector<int>red(33), blue(33), score(33), dice(10);
	vector<pair<int, bool>>piece(4, { 0,false }); // false = red , true = blue
	vector<bool>visited(33);
	for (int i = 0; i <= 20; i++)
	{
		red[i] = i + 1;
		score[i] = i * 2;
	}
	red[20] = red[32] = 32;
	blue[5] = 21, blue[21] = 22, blue[22] = 23, blue[23] = 29;
	blue[10] = 24, blue[24] = 25, blue[25] = 29,
	blue[15] = 26, blue[26] = 27, blue[27] = 28, blue[28] = 29;
	blue[29] = 30, blue[30] = 31, blue[31] = 20, blue[20] = blue[32] = 32;
	score[21] = 13, score[22] = 16, score[23] = 19, score[24] = 22, score[25] = 24, score[26] = 28,
	score[27] = 27, score[28] = 26, score[29] = 25, score[30] = 30, score[31] = 35;
	for (auto& i : dice)
	{
		cin >> i;
	}
	auto move = [&](int d, int p)
		{
			auto [a, b] = piece[p];
			if (!b)
			{
				while (a != 32 && d--)
				{
					a = red[a];
				}
			}
			else
			{
				while (a != 32 && d--)
				{
					a = blue[a];
				}
			}
			if (visited[a] && a != 32)
			{
				return make_tuple(-1, false);
			}
			return make_tuple(a, true);
		};
	function<void(int, int)> dfs = [&](int depth, int sum)->void
		{
			if (depth == 10)
			{
				ans = max(ans, sum);
				return;
			}
			for (int i = 0; i < 4; ++i)
			{
				auto [a, b] = piece[i];
				if (a == 32)
				{
					continue;
				}
				auto [c, d] = move(dice[depth], i);
				if (d)
				{
					bool was = visited[c];
					visited[a] = false;
					visited[c] = true;
					piece[i] = { c, (c == 5 || c == 10 || c == 15) ? true : b };
					dfs(depth + 1, sum + ((c == 32) ? 0 : score[c]));
					piece[i] = { a, b };
					visited[a] = true;
					visited[c] = was;
				}
			}
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}