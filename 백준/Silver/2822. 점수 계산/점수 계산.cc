#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pii>v(8);
	vector<int>ans;
	for (int i = 0; i < 8; ++i)
	{
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
		{
			return a.first > b.first;
		});
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		sum += v[i].first;
		ans.push_back(v[i].second);
	}
	sort(ans.begin(), ans.end());
	cout << sum << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}