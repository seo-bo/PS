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
	int n = 0;
	cin >> n;
	priority_queue<int>pq;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else
		{
			for (int j = 0; j < a; ++j)
			{
				int temp = 0;
				cin >> temp;
				pq.push(temp);
			}
		}
	}
	return 0;
}