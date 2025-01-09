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
	int n = 0;
	cin >> n;
	queue<int>q;
	while (1)
	{
		int t = 0;
		cin >> t;
		if (t == -1)
		{
			break;
		}
		if (!t)
		{
			q.pop();
		}
		else
		{
			if (q.size() >= n)
			{
				continue;
			}
			q.push(t);
		}
	}
	if (q.empty())
	{
		cout << "empty";
	}
	else
	{
		while (!q.empty())
		{
			cout << q.front() << ' ';
			q.pop();
		}
	}
	return 0;
}