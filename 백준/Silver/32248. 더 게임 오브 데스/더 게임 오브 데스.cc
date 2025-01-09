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
	ll n = 0, t = 0;
	cin >> n >> t;
	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	int x = 1;
	deque<int>dq;
	vector<bool>visited(n + 1, false);
	visited[1] = true;
	vector<int>temp;
	temp.push_back(1);
	while (t)
	{
		if (!visited[v[x]])
		{
			x = v[x];
			visited[x] = true;
			temp.push_back(x);
			t--;
		}
		else
		{
			while (!temp.empty() && temp.back() != v[x])
			{
				dq.push_front(temp.back());
				temp.pop_back();
			}
			dq.push_front(v[x]);
			x = v[x];
			t--;
			break;
		}
	}
	if (!t)
	{
		cout << x;
		return 0;
	}
	t %= dq.size();
	cout << dq[t];
	return 0;
}