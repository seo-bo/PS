#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, a = 0;
	cin >> n;
	a = (int)round(((lb)n / 100) * 15);
	deque<int>dq;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		dq.push_back(temp);
	}
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	sort(dq.begin(), dq.end());
	for (int i = 0; i < a; ++i)
	{
		dq.pop_front();
		dq.pop_back();
	}
	ll sum = 0;
	while (!dq.empty())
	{
		sum += dq.front();
		dq.pop_front();
	}
	cout << (ll)round((lb)sum / (n - 2 * a));
	return 0;
}