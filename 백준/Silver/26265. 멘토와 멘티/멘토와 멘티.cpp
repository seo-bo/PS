#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<pair<string,string>>v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [] (const pair<string,string> &a, const pair<string,string> &b)
		{
			if (a.first == b.first)
			{
				return a.second > b.second;
			}
			return a.first < b.first;
		});
	for (auto& i : v)
	{
		cout << i.first << " " << i.second << "\n";
	}
	return 0;
}
