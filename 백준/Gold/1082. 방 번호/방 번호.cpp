#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N = 0, M = 0;
vector<pair<int, char>>v;
int cost[10];
int main(void)
{
	string str;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		v[i].second = i + '0';
		cost[i] = v[i].first;
	}
	sort(v.begin(), v.end());
	cin >> M;
	if (v[0].second != '0')
	{
		if (M - v[0].first >= 0)
		{
			str.push_back(v[0].second);
			M -= v[0].first;
		}
	}
	else
	{
		if (N == 1)
		{
			cout << 0;
			return 0;
		}
		if (M - v[1].first >= 0)
		{
			str.push_back(v[1].second);
			M -= v[1].first;
		}
	}
	while (M - v[0].first >=0)
	{
		str.push_back(v[0].second);
		M -= v[0].first;
	}
	int len = str.length();
	for (int i = 0; i < len; ++i)
	{
		int start = (int)str[i] - '0';
		for (int j = N-1; j > start; --j)
		{
			if (M + cost[start] - cost[j] >= 0)
			{
				str[i] = j + '0';
				M = M + cost[start] - cost[j];
				break;
			}
		}
	}
	if (str[0] == '0')
	{
		cout << 0;
		return 0;
	}
	cout << str;
	return 0;
}