#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>parent(n + 1);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int num) ->int
		{
			if (parent[num] == num)
			{
				return num;
			}
			return parent[num] = find(parent[num]);
		};
	auto Union = [&](int num1, int num2)
		{
			int r1 = find(num1);
			int r2 = find(num2);
			if (r1 == r2)
			{
				return;
			}
			parent[r2] = r1;
		};
	for (int i = 0; i < n - 2; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		Union(start, end);
	}
	for (int i = 2; i <= n; ++i)
	{
		if (find(1) != find(i))
		{
			cout << 1 << " " << i;
			break;
		}
	}
	return 0;
}