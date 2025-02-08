#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<pair<int, int>>v(N + 1);
	vector<bool>alive(N + 1, true);
	alive[0] = false;
	for (int i = 1; i <= N; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	int M = 0;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int temp = 0;
		cin >> temp;
		alive[temp] = false;
	}
	int result = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (alive[i] && alive[v[i].first] && alive[v[i].second])
		{
			result++;
		}
	}
	cout << result;
	return 0;
}