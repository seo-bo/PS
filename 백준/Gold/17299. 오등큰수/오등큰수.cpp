#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pii>s;
	vector<int>a(1000002), ans(n), v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		a[v[i]]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (s.empty() || s.back().first >= a[v[i]])
		{
			s.push_back(make_pair(a[v[i]], i));
		}
		else if (s.back().first < a[v[i]])
		{
			while (!s.empty() && s.back().first < a[v[i]])
			{
				ans[s.back().second] = v[i];
				s.pop_back();
			}
			s.push_back(make_pair(a[v[i]], i));
		}
	}
	while (!s.empty())
	{
		ans[s.back().second] = -1;
		s.pop_back();
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}