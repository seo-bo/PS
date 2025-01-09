#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<bool>prime(2000003, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= 2000000; ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 2000000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	int pivot = 2000000 - (n - 1) * m;
	bool flag = false;
	for (int i = 1; i <= pivot; ++i)
	{
		bool check = true;
		for (int j = 0; j < n; ++j)
		{
			int temp = i + j * m;
			if (prime[temp])
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << i + j * m << ' ';
			}
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << -1;
	}
	return 0;
}
