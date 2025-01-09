#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0, cnt = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int target = n;
	for (int i = n - 1; i >= 0; --i)
	{
		if (v[i] == target)
		{
			cnt++;
			target--;
		}
	}
	cout << n - cnt;
	return 0;
}