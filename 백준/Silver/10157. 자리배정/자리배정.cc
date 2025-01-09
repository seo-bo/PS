#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c = 0, r = 0, k = 0, cnt = 1, d = 0;
	cin >> c >> r >> k;
	vector<vector<int>>dir = { {1,0},{0,1},{-1,0},{0,-1} };
	vector<vector<bool>>v(r + 1, vector<bool>(c + 1, false));
	if (c * r < k)
	{
		cout << 0;
		return 0;
	}
	pii pos = make_pair(1, 1);
	while (cnt < k)
	{
		auto [a, b] = pos;
		v[a][b] = true;
		int nx = a + dir[d][0];
		int ny = b + dir[d][1];
		if (!(nx >= 1 && ny >= 1 && nx <= r && ny <= c && !v[nx][ny]))
		{
			d = (d + 1) % 4;
		}
		pos = make_pair(a + dir[d][0], b + dir[d][1]);
		cnt++;
	}
	cout << pos.second << ' ' << pos.first;
	return 0;
}