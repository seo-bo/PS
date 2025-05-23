#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<int, int>mm;
	int n = 0;
	cin >> n;
	for (int i = 0; i < 3 * n; ++i)
	{
		int temp = 0;
		cin >> temp;
		mm[temp]++;
	}
	set<int>s;
	for (auto& [a, b] : mm)
	{
		if (b == 1)
		{
			s.insert(a);
		}
	}
	int ans = 0;
	for (int a = 1; a <= 100; ++a)
	{
		for (int b = a + 1; b <= 100; ++b)
		{
			for (int c = b + 1; c <= 100; ++c)
			{
				set<int>ok = s;
				int pivot = -1;
				if (ok.find(a) == ok.end() && mm.find(a) == mm.end())
				{
					pivot = a;
				}
				else
				{
					ok.erase(a);
				}
				if (ok.find(b) == ok.end() && mm.find(b) == mm.end())
				{
					pivot = max(pivot, b);
				}
				else
				{
					ok.erase(b);
				}
				if (ok.find(c) == ok.end() && mm.find(c) == mm.end())
				{
					pivot = max(pivot, c);
				}
				else
				{
					ok.erase(c);
				}
				if (pivot == -1)
				{
					continue;
				}
				auto it = ok.upper_bound(pivot);
				if (it == ok.end())
				{
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}