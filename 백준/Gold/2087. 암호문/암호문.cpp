#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n;
	vector<pair<int, string>>left;
	vector<int>v(n, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	cin >> k;
	int mid = n / 2;
	for (int i = 0; i < (1 << mid); ++i)
	{
		int sum = 0;
		string str = "";
		for (int j = 0; j < mid; ++j)
		{
			if (i & (1 << j))
			{
				sum += v[j];
				str += '1';
			}
			else
			{
				str += '0';
			}
		}
		left.push_back(make_pair(sum, str));
	}
	sort(left.begin(), left.end());
	for (int i = 0; i < (1 << (n - mid)); ++i)
	{
		int sum = 0;
		string str = "";
		for (int j = 0; j < n - mid; ++j)
		{
			if (i & (1 << j))
			{
				sum += v[mid + j];
				str += '1';
			}
			else
			{
				str += '0';
			}
		}
		int target = k - sum;
		if (target >= 0)
		{
			auto it = lower_bound(left.begin(), left.end(), make_pair(target, string("")));
			if (it != left.end() && it->first == target)
			{
				cout << it->second << str;
				return 0;
			}
		}
	}
	return 0;
}