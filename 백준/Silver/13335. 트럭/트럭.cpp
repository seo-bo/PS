#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, w = 0, l = 0, ans = 0;
	cin >> n >> w >> l;
	deque<int>a;
	deque<pii>b;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		a.push_back(temp);
	}
	int cur = 0;
	while (!a.empty() || !b.empty())
	{
		ans++;
		if (!b.empty() && b.front().second == ans)
		{
			cur -= b.front().first;
			b.pop_front();
		}
		if (!a.empty() && cur + a.front() <= l)
		{
			cur += a.front();
			b.push_back({ a.front(), ans + w });
			a.pop_front();
		}
	}
	cout << ans;
	return 0;
}