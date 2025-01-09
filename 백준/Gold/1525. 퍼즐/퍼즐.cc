#include <bits/stdc++.h>
#include <unordered_set>
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
	string t = "123456780", n;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < 9; ++i)
	{
		int temp = 0;
		cin >> temp;
		n += (temp + '0');
	}
	queue<pair<string, int>>q;
	unordered_set<string>visited;
	q.push(make_pair(n, 0));
	visited.insert(n);
	while (!q.empty())
	{
		auto [a, c] = q.front();
		q.pop();
		if (a == t)
		{
			cout << c;
			return 0;
		}
		int idx = a.find('0'), x = idx / 3, y = idx % 3;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{
				string temp = a;
				swap(temp[x * 3 + y], temp[nx * 3 + ny]);
				if (visited.find(temp) != visited.end())
				{
					continue;
				}
				visited.insert(temp);
				q.push(make_pair(temp, c + 1));
			}
		}
	}
	cout << -1;
	return 0;
}