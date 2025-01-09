#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<deque<int>>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[temp].push_back(i);
	}
	n--;
	vector<int>ans;
	ans.push_back(v[0].front());
	v[0].pop_front();
	while (n--)
	{
		for (int i = ans.size(); i >= 0; --i)
		{
			if (v[i].empty())
			{
				continue;
			}
			int pivot = v[i].front();
			int cnt = 0;
			for (auto& j : ans)
			{
				if (j > pivot)
				{
					cnt++;
				}
			}
			if (cnt == i)
			{
				ans.push_back(pivot);
				v[i].pop_front();
				break;
			}
		}
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}