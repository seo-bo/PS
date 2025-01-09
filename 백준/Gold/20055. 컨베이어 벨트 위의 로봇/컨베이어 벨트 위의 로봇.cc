#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	deque<pair<int, bool>>dq;
	int crash = 0, n = 0, k = 0;
	cin >> n >> k;
	int pivot = 2 * n;
	for (int i = 0; i < pivot; ++i)
	{
		int a = 0;
		cin >> a;
		dq.push_back(make_pair(a, false));
	}
	auto sv = [&]
		{
			dq.push_front(dq.back());
			dq.pop_back();
			if (dq[n - 1].second)
			{
				dq[n - 1].second = false;
			}
			for (int i = dq.size() - 1; i >= 0; --i)
			{
				auto& [a, b] = dq[i];
				auto& [c, d] = dq[(i + 1) % pivot];
				if (c && b && !d)
				{
					swap(b, d);
					c--;
					if ((i + 1) % pivot == n - 1)
					{
						d = false;
					}
					if (!c)
					{
						crash++;
					}
				}
			}
			auto& [a, b] = dq[0];
			if (a && !b)
			{
				a--;
				if (!a)
				{
					crash++;
				}
				b = true;
			}
		};
	for (int i = 0;; ++i)
	{
		if (crash >= k)
		{
			cout << i;
			return 0;
		}
		sv();
	}
	return 0;
}