#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = INT_MAX;
	cin >> n;
	deque<int>dq;
	for (int i = 0; i < 2 * n; ++i)
	{
		int temp = 0;
		cin >> temp;
		dq.push_back(temp);
	}
	sort(dq.begin(), dq.end());
	while (!dq.empty())
	{
		int a = dq.front();
		int b = dq.back();
		dq.pop_front(), dq.pop_back();
		ans = min(ans, a + b);
	}
	cout << ans;
	return 0;
}