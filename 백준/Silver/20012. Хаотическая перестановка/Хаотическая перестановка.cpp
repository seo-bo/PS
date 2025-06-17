#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<int>ans;
	auto check = [&](int a)
		{
			if (a + 2 <= n - 1)
			{
				if (v[a] < v[a + 1] && v[a + 1] < v[a + 2])
				{
					ans.push_back(a + 2);
					swap(v[a + 2], v[a + 1]);
					return true;
				}
				if (v[a] > v[a + 1] && v[a + 1] > v[a + 2])
				{
					ans.push_back(a + 2);
					swap(v[a + 2], v[a + 1]);
					return true;
				}
			}
			return false;
		};

	for (int i = 0; i < n; ++i)
	{
		check(i);
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}