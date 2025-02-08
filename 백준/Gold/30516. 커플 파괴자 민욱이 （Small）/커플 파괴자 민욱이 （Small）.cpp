#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	deque<deque<int>>couple;
	vector<int>v(n);
	deque<int>temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	if (n == 2 && v[0] == v[1] && v[0] != 0)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!i)
		{
			temp.push_back(v[i]);
			continue;
		}
		if (v[i - 1] == v[i] && v[i] != 0)
		{
			couple.push_back(temp);
			deque<int>().swap(temp);
		}
		temp.push_back(v[i]);
	}
	if (!temp.empty())
	{
		couple.push_back(temp);
		deque<int>().swap(temp);
	}
	if (n >= 3 && couple.size() == 2 && couple[0].front() == couple[1].back() && couple[0].front() != 0)
	{
		if (couple[1].size() >= 2)
		{
			int tt = couple[1].back();
			temp.push_back(tt);
			couple[1].pop_back();
			couple.push_back(temp);
		}
		else if (couple[0].size() >= 2)
		{
			int tt = couple[0].front();
			temp.push_back(tt);
			couple[0].pop_front();
			couple.push_front(temp);
		}
	}
	vector<pii>comb(1);
	for (auto& i : couple)
	{
		comb.push_back(make_pair(i.front(), i.back()));
	}
	int p = couple.size();
	vector<int>pivot(p, 0);
	iota(pivot.begin(), pivot.end(), 1);
	vector<int>ans;
	vector<bool>visited(n + 1, false);
	function<void(int)> dfs = [&](int depth)
		{
			if (depth == p)
			{
				if (ans == pivot && p != 1)
				{
					return;
				}
				cout << p << '\n';
				for (auto& i : couple)
				{
					cout << i.size() << ' ';
					comb.push_back(make_pair(i.front(), i.back()));
				}
				cout << '\n';
				for (auto& i : ans)
				{
					cout << i << ' ';
				}
				exit(0);
			}
			for (int i = 1; i < comb.size(); ++i)
			{
				if (visited[i])
				{
					continue;
				}
				if (depth == 0 || comb[ans.back()].second != comb[i].first || comb[i].first == 0)
				{
					visited[i] = true;
					ans.push_back(i);
					dfs(depth + 1);
					ans.pop_back();
					visited[i] = false;
				}
			}
		};
	dfs(0);
	cout << -1;
	return 0;
}