#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	int n = 0;
	cin >> n;
	vector<vector<int>>oper = { {0,3},{1,2} }, rev = { {1,3},{0,2} };
	int x = n, y = 1, t = 0;
	if (n % 2)
	{
		cout << n * (n - 1) << '\n';
	}
	else
	{
		cout << (n + 1) * (n - 1) << '\n';
	}
	cout << format("{} {}\n", x, y);
	auto sv = [&](vector<vector<int>>& v)
		{
			for (int i = 0, idx = 0, cnt = n - 1, pnt = 0; i < n; ++i, idx = (idx + 1) % 2, --cnt, ++pnt)
			{
				cout << n << ' ';
				for (int j = 0; j < n; ++j)
				{
					int pivot = v[idx][0];
					if (i % 2 == 0 && j == cnt)
					{
						pivot = v[idx][1];
					}
					else if (i % 2 && j == pnt)
					{
						pivot = v[idx][1];
					}
					x = x + dir[pivot][0];
					y = y + dir[pivot][1];
					cout << format("{} {} ", x, y);
				}
				cout << '\n';
			}
			if (n % 2 == 0)
			{
				cout << n << ' ';
				x = x + dir[3][0];
				y = y + dir[3][1];
				cout << format("{} {} ", x, y);
				for (int i = 0; i < n - 1; ++i)
				{
					x = x + dir[t][0];
					y = y + dir[t][1];
					cout << format("{} {} ", x, y);
				}
				cout << '\n';
			}
			t = (t + 1) % 2;
		};
	for (int i = 0; i < n - 1; ++i)
	{
		if (!t)
		{
			sv(oper);
		}
		else
		{
			sv(rev);
		}
	}
	return 0;
}