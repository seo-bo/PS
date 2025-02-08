#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 직접 써보는게 더 낫다!
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int h = 0, w = 0, x = 0, y = 0;
	cin >> h >> w >> x >> y;
	vector<vector<int>>v(h + x, vector<int>(w + y, 0));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = x; i < h; ++i)
	{
		for (int j = y; j < w; ++j)
		{
			v[i][j] = v[i][j] - v[i - x][j - y];
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}