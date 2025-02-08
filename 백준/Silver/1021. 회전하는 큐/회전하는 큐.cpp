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
	deque<int>dq;
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		dq.push_back(i);
	}
	ll ans = 0;
	for (auto& i : v)
	{
		int left = 0, right = 0;
		deque<int>L = dq;
		deque<int>R = dq;
		while (L.front() != i)
		{
			int temp = L.back();
			L.pop_back();
			L.push_front(temp);
			left++;
		}
		while (R.front() != i)
		{
			int temp = R.front();
			R.pop_front();
			R.push_back(temp);
			right++;
		}
		if (left > right)
		{
			dq = R;
			ans += right;
		}
		else
		{
			dq = L;
			ans += left;
		}
		dq.pop_front();
	}
	cout << ans;
	return 0;
}