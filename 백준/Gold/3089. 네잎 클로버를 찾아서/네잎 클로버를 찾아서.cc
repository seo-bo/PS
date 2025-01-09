#include <bits/stdc++.h>
#define P 100000
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, x = P, y = P;
	cin >> n >> m;
	string str;
	vector<vector<int>>xpos(100001 + P);
	vector<vector<int>>ypos(100001 + P);
	for (int i = 0; i < n; ++i)
	{
		int nx = 0, ny = 0;
		cin >> nx >> ny;
		xpos[nx + P].push_back(ny + P);
		ypos[ny + P].push_back(nx + P);
	}
	for (int i = 0; i <= 200000; ++i)
	{
		if (!xpos[i].empty())
		{
			sort(xpos[i].begin(), xpos[i].end());
		}
		if (!ypos[i].empty())
		{
			sort(ypos[i].begin(), ypos[i].end());
		}
	}
	cin >> str;
	for (auto& i : str)
	{
        switch (i)
        {
        case 'L':
        {
            auto it = lower_bound(ypos[y].begin(), ypos[y].end(), x);
            if (it != ypos[y].begin())
            {
                x = *(--it);
            }
            break;
        }
        case 'R':
        {
            auto it = upper_bound(ypos[y].begin(), ypos[y].end(), x);
            if (it != ypos[y].end())
            {
                x = *it;
            }
            break;
        }
        case 'U':
        {
            auto it = upper_bound(xpos[x].begin(), xpos[x].end(), y);
            if (it != xpos[x].end())
            {
                y = *it;
            }
            break;
        }
        case 'D':
        {
            auto it = lower_bound(xpos[x].begin(), xpos[x].end(), y);
            if (it != xpos[x].begin())
            {
                y = *(--it);
            }
            break;
        }
        }
	}
    cout << x - P << ' ' << y - P;
	return 0;
}