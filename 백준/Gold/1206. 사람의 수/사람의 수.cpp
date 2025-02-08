#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		string temp;
		cin >> temp;
		string inpu;
		for (auto& j : temp)
		{
			if (j == '.')
			{
				continue;
			}
			inpu += j;
		}
		i = stoi(inpu);
	}
	int idx = 1;
	auto search = [&](int idx) -> bool
		{
			for (auto& k : v)
			{
				int left = 0, right = idx * 100;
				bool check = false;
				while (left <= right)
				{
					int mid = (left + right) / 2;
					int t = mid * 1000 / idx;
					if (t == k)
					{
						check = true;
						break;
					}
					if (t > k)
					{
						right = mid - 1;
					}
					else
					{
						left = mid + 1;
					}
				}
				if (!check)
				{
					return false;
				}
			}
			return true;
		};
	while (1)
	{
		if (search(idx))
		{
			cout << idx;
			return 0;
		}
		idx++;
	}
	return 0;
}