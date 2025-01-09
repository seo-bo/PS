#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int h, w, q;
	cin >> h >> w >> q;
	vector<set<int>> row(h + 1);
	vector<set<int>> col(w + 1);
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			row[i].insert(j);
			col[j].insert(i);
		}
	}
	int cnt = h * w;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (row[a].count(b))
		{
			row[a].erase(b);
			col[b].erase(a);
			cnt--;
		}
		else
		{
			auto up = col[b].lower_bound(a);
			if (up != col[b].begin())
			{
				up--;
				row[*up].erase(b);
				col[b].erase(up);
				cnt--;
			}
			auto down = col[b].lower_bound(a);
			if (down != col[b].end() && *down > a)
			{
				row[*down].erase(b);
				col[b].erase(down);
				cnt--;
			}
			auto left = row[a].lower_bound(b);
			if (left != row[a].begin())
			{
				left--;
				col[*left].erase(a);
				row[a].erase(left);
				cnt--;
			}
			auto right = row[a].lower_bound(b);
			if (right != row[a].end() && *right > b)
			{
				col[*right].erase(a);
				row[a].erase(right);
				cnt--;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
