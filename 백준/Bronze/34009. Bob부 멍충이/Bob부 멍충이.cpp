#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	deque<ll>dq;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		dq.push_back(temp);
	}
	sort(dq.begin(), dq.end());
	ll a = 0, b = 0;
	int t = ((int)dq.size() % 2);
	while (!dq.empty())
	{
		if (t)
		{
			b += dq.front();
			dq.pop_front();
		}
		else
		{
			a += dq.back();
			dq.pop_back();
		}
		if (b >= a)
		{
			cout << "Bob";
			return 0;
		}
		t = (t + 1) % 2;
	}
	cout << "Alice";
	return 0;
}