#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>A(n), B(n);
	for (auto& i : A)
	{
		cin >> i;
	}
	for (auto& i : B)
	{
		cin >> i;
	}
	auto sv = [&](vector<int>& v)
		{
			int len = 0;
			for (int i = 0; i < n; ++i)
			{
				int x = i;
				vector<int>s;
				do
				{
					auto it = lower_bound(s.begin(), s.end(), v[x]);
					if (it == s.end())
					{
						s.push_back(v[x]);
					}
					else
					{
						*it = v[x];
					}
					x = (x + 1) % n;
				} while (x != i);
				len = max(len, (int)s.size());
			}
			return len;
		};
	int a = sv(A), b = sv(B);
	if (a > b)
	{
		cout << "YJ Win!";
	}
	else if (a < b)
	{
		cout << "HG Win!";
	}
	else
	{
		cout << "Both Win!";
	}
	return 0;
}