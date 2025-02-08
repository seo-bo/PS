#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<bool>p(100001, true);
	p[0] = p[1] = false;
	for (ll i = 2; i * i <= 100000; ++i)
	{
		if (p[i])
		{
			for (ll j = i * i; j <= 100000; j += i)
			{
				p[j] = false;
			}
		}
	}
	vector<int>prime;
	for (int i = 2; i <= 100000; ++i)
	{
		if (p[i])
		{
			prime.push_back(i);
		}
	}
	vector<vector<pii>>div(100001);
	for (int i = 2; i <= 100000; ++i)
	{
		int pivot = i;
		for (auto& j : prime)
		{
			if (pivot == 1)
			{
				break;
			}
			if (p[pivot])
			{
				div[i].push_back(make_pair(pivot, 1));
				break;
			}
			int cnt = 0;
			while (pivot > 1 && pivot % j == 0)
			{
				cnt++;
				pivot /= j;
			}
			if (cnt)
			{
				div[i].push_back(make_pair(j, cnt));
			}
		}
	}
	vector<int>ans(100001, 0);
	int n = 0;
	cin >> n;
	n = 2 * n - 1;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	if (v[0] == "0")
	{
		cout << "mint chocolate";
		return 0;
	}
	for (auto& [a, b] : div[abs(stoi(v[0]))])
	{
		ans[a] += b;
	}
	for (int i = 1; i < n; i += 2)
	{
		string a = v[i];
		int b = abs(stoi(v[i + 1]));
		if (b == 0)
		{
			cout << "mint chocolate";
			return 0;
		}
		if (a == "*")
		{
			for (auto& [c, d] : div[b])
			{
				ans[c] += d;
			}
		}
		else
		{
			for (auto& [c, d] : div[b])
			{
				ans[c] -= d;
			}
		}
	}
	for (auto& i : ans)
	{
		if (i < 0)
		{
			cout << "toothpaste";
			return 0;
		}
	}
	cout << "mint chocolate";
	return 0;
}