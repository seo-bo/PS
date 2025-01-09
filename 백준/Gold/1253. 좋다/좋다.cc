#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		int left = 0, right = n - 1;
		while (left < right)
		{
			ll sum = v[left] + v[right];
			if (sum == v[i])
			{
				if (left != i && right != i)
				{
					ans++;
					break;
				}
				left == i ? left++ : right--;
				continue;
			}
			sum < v[i] ? left++ : right--;
		}
	}
	cout << ans;
	return 0;
}