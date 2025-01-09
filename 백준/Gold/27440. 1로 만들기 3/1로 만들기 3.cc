#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<ll, int>visited;

void bfs(ll start)
{
	queue<pair<ll, ll>>q;
	q.push(make_pair(start, 0));
	visited.insert(make_pair(start, 0));
	while (!q.empty())
	{
		pair<ll, ll>current = q.front();
		q.pop();
		if (current.first == 1)
		{
			cout << current.second;
			return;
		}
		if (!(current.first % 3) && visited.find((current.first / 3)) == visited.end())
		{
			q.push(make_pair((current.first / 3), current.second + 1));
			visited.insert(make_pair((current.first / 3), 1));
		}
		if (!(current.first % 2) && visited.find((current.first / 2)) == visited.end())
		{
			q.push(make_pair((current.first / 2), current.second + 1));
			visited.insert(make_pair((current.first / 2), 1));
		}
		if (visited.find(current.first - 1) == visited.end())
		{
			q.push(make_pair((current.first - 1), current.second + 1));
			visited.insert(make_pair((current.first - 1), 1));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	bfs(num);
	return 0;
}