#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v;
	vector<int>temp;
	function<void(int, int)> dfs = [&](int idx, int sum)
		{
			if (sum == 0)
			{
				v.push_back(temp);
				return;
			}
			if (idx > n || idx > sum)
			{
				return;
			}
			temp.push_back(idx);
			dfs(idx + 2, sum - idx);
			temp.pop_back();
			dfs(idx + 1, sum);
		};
	dfs(1, n);
	string base = to_string(n);
	base += "=";
	for (auto& i : v)
	{
		string str = base;
		for (auto& j : i)
		{
			str += to_string(j);
			str += "+";
		}
		str.pop_back();
		cout << str << '\n';
	}
	return 0;
}