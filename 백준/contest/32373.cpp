#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0, k = 0;
	cin >> n >> k;
	if (k == 1)
	{
		cout << yes;
		return 0;
	}
	vector<ll>v(n);
	vector<ll>temp(n);
	int idx = 0;
	for (auto& i : v)
	{
		cin >> i;
		temp[i] = idx++;
	}
	bool check = true;
	for (int i = 0; i < n; ++i)
	{
		if (temp[i] % k != i % k)
		{
			check = false;
			break;
		}
	}
	cout << ((check) ? yes : no);
	return 0;
}
