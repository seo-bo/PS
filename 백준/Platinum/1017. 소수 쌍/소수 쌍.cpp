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
	vector<bool>p(2002, true);
	auto prime = [&]
		{
			p[0] = p[1] = false;
			for (int i = 2; i <= sqrt(2000); ++i)
			{
				if (p[i])
				{
					for (int j = i * i; j <= 2000; j += i)
					{
						p[j] = false;
					}
				}
			}
		};
	prime();
	bool check = false;
	int n = 0, f = 0;
	cin >> n >> f;
	if (f % 2)
	{
		check = true;
	}
	vector<int>left;
	vector<int>right;
	int siz = n / 2;
	left.push_back(f);
	for (int i = 1; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (check)
		{
			if (temp % 2)
			{
				left.push_back(temp);
			}
			else
			{
				right.push_back(temp);
			}
		}
		else
		{
			if (temp % 2)
			{
				right.push_back(temp);
			}
			else
			{
				left.push_back(temp);
			}
		}
	}
	if (left.size() != right.size())
	{
		cout << -1;
		return 0;
	}
	vector<int>ans;
	vector<vector<int>>graph(siz);
	for (int i = 0; i < siz; ++i)
	{
		for (int j = 0; j < siz; ++j)
		{
			if (p[left[i] + right[j]])
			{
				graph[i].push_back(j);
			}
		}
	}
	vector<int>match(siz, -1);
	vector<int>r_match(siz, -1);
	vector<bool>visited(siz, false);
	function<bool(int)> dfs = [&](int num) ->bool
		{
			if (!num || visited[num]) 
			{
				// 일단 첫번째 놈은 불변이고 r_match로 역으로 추적하기 때문에
				return false;
			}
			visited[num] = true;
			for (auto& i : graph[num])
			{
				if (r_match[i] == -1 || dfs(r_match[i]))
				{
					match[num] = i;
					r_match[i] = num;
					return true;
				}
			}
			return false;
		};
	for (auto& i : graph[0])
	{
		vector<int>(siz, -1).swap(match);
		vector<int>(siz, -1).swap(r_match);
		bool poss = true;
		match[0] = i;
		r_match[i] = 0;
		int cnt = 1;
		for (int j = 1; j < siz; ++j)
		{
			vector<bool>(siz, false).swap(visited);
			if (!dfs(j))
			{
				poss = false;
				break;
			}
		}
		if (poss)
		{
			ans.push_back(right[i]);
		}
	}
	if (ans.empty())
	{
		cout << -1;
	}
	else
	{
		sort(ans.begin(), ans.end());
		for (auto& i : ans)
		{
			cout << i << " ";
		}
	}
	return 0;
}