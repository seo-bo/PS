#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>v(3);
	ll sum = 0;
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	if (sum % 3)
	{
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	queue<vector<ll>>q;
	set<vector<ll>>visited;
	visited.insert(v);
	q.push(v);
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		if (cur[0] == cur[1] && cur[1] == cur[2])
		{
			cout << 1;
			return 0;
		}
		for (int i = 0; i < 2; ++i)
		{
			for (int j = i + 1; j < 3; ++j)
			{
				if (cur[i] != cur[j])
				{
					vector<ll>temp = cur;
					temp[i] *= 2;
					temp[j] -= cur[i];
					sort(temp.begin(), temp.end());
					if (visited.find(temp) == visited.end())
					{
						visited.insert(temp);
						q.push(temp);
					}
				}
			}
		}
	}
	cout << 0;
	return 0;
}