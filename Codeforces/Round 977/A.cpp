#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>>pq;
		for (int i = 0; i < n; ++i)
		{
			ll temp = 0;
			cin >> temp;
			pq.push(temp);
		}
		while (pq.size() > 1)
		{
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();
			ll av = (a + b) / 2;
			pq.push(av);
		}
		cout << pq.top() << '\n';
	}
	return 0;
}
