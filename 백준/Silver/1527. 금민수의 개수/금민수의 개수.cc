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
	ll a = 0, b = 0, cnt = 0;
	unordered_set<string>visited;
	cin >> a >> b;
	queue<string>q;
	q.push("4"), q.push("7");
	visited.insert("4");
	visited.insert("7");
	if (a <= 4 && 4 <= b)
	{
		cnt++;
	}
	if (a <= 7 && 7 <= b)
	{
		cnt++;
	}

	while (!q.empty())
	{
		auto k = q.front();
		q.pop();
		string k4 = k, k7 = k;
		k4 += '4', k7 += '7';
		ll a4 = stoll(k4), a7 = stoll(k7);
		if (a4 <= b && visited.find(k4) == visited.end())
		{
			if (a <= a4)
			{
				cnt++;
			}
			q.push(k4);
			visited.insert(k4);
		}
		if (a7 <= b && visited.find(k7) == visited.end())
		{
			if (a <= a7)
			{
				cnt++;
			}
			q.push(k7);
			visited.insert(k7);
		}
	}
	cout << cnt;
	return 0;
}