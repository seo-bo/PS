#include <bits/stdc++.h>
#include <unordered_map>
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, M = 0;
	cin >> N >> M;
	vector<pair<int, int>>v;
	for (int i = 1; i <= M; ++i)
	{
		int h1 = 0, h2 = 0;
		cin >> h1 >> h2;
		v.push_back(make_pair(h1, i));
		v.push_back(make_pair(h2, i));
	}
	sort(v.begin(), v.end());
	deque<int>dq;
	for (auto& i : v)
	{
		dq.push_back(i.second);
	}
	while (N > 1)
	{
		int num = dq.front();
		dq.push_back(num);
		dq.pop_front();
		N--;
	}
	cout << dq.front();
	return 0;
}
