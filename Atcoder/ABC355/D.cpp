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
	vector<pair<int, int>>v;
	for (int i = 0; i < N; ++i)
	{
		int left = 0, right = 0;
		cin >> left >> right;
		v.push_back(make_pair(left, 1));
		v.push_back(make_pair(right, -1));
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
		{
			return a.first == b.first ? a.second > b.second : a.first < b.first;
		});

	int section = 0;
	ll result = 0;
	for (auto& i : v)
	{
		if (i.second == 1)
		{
			result += section;
			section++;
		}
		else
		{
			section--;
		}
	}
	cout << result;
	return 0;
}
