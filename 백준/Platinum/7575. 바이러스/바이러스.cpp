#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	int lp = INT_MAX, idx = -1;
	vector<vector<int>>v(n);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp < lp)
		{
			lp = temp;
			idx = i;
		}
		for (int j = 0; j < temp; ++j)
		{
			int a = 0;
			cin >> a;
			v[i].push_back(a);
		}
	}
	if (k > lp)
	{
		cout << "NO";
		return 0;
	}
	auto fail = [&](vector<int>& a)
		{
			vector<int>pattern(k, 0);
			int left = 0;
			for (int right = 1; right < k; ++right)
			{
				while (left > 0 && a[left] != a[right])
				{
					left = pattern[left - 1];
				}
				if (a[left] == a[right])
				{
					pattern[right] = ++left;
				}
			}
			return pattern;
		};
	auto kmp = [&](vector<int>& pattern, vector<int>& a, vector<int>& b)
		{
			int left = 0;
			for (int right = 0; right < b.size(); ++right)
			{
				while (left > 0 && a[left] != b[right])
				{
					left = pattern[left - 1];
				}
				if (a[left] == b[right])
				{
					left++;
					if (left == k)
					{
						return true;
					}
				}
			}
			return false;
		};
	for (int i = 0; i <= lp - k; ++i)
	{
		vector<int>s1(v[idx].begin() + i, v[idx].begin() + i + k);
		vector<int>s2(s1.rbegin(), s1.rend());
		vector<int>p1 = fail(s1);
		vector<int>p2 = fail(s2);
		bool flag = true;
		for (int j = 0; j < n; ++j)
		{
			if (idx == j)
			{
				continue;
			}
			if (!kmp(p1, s1, v[j]) && !kmp(p2, s2, v[j]))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}