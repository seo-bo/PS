#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pc;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	deque<pc>dq;
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		dq.push_back(make_pair(str[i], i));
	}
	sort(dq.begin(), dq.end(), [&](const pc& a, const pc& b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first < b.first;
		});
	for (int i = 0; i < m; ++i)
	{
		dq.pop_front();
	}
	sort(dq.begin(), dq.end(), [&](const pc& a, const pc& b)
		{
			return a.second < b.second;
		});
	for (auto& [a, b] : dq)
	{
		cout << a;
	}
	return 0;
}