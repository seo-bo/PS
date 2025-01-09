#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n), a(n), b(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		a[i] += v[i] - temp;
		b[i] += temp - v[i];
		if (a[i] == 0 || i == n - 1)
		{
			continue;
		}
		if (a[i] < 0)
		{
			a[n - 1] -= a[i];			
		}
		else
		{
			if (i != n - 2)
			{
				a[n - 1] += a[i];
			}
			else
			{
				a[n - 1] -= a[i];
			}
		}
		if (b[i] < 0)
		{
			b[n - 1] -= b[i];
		}
		else
		{
			if (i != n - 2)
			{
				b[n - 1] += b[i];
			}
			else
			{
				b[n - 1] -= b[i];
			}
		}
	}
	cout << max(a[n - 1], b[n - 1]);
	return 0;
}