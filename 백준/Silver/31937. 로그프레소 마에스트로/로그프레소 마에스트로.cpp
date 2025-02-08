#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

vector<tuple<int, int, int>>v;
int n = 0, m = 0, k = 0;
bool infected[1001] = { false, };
bool check[1001] = { false, };

bool simulation(int start)
{
	int cnt = 1;
	memset(infected, false, sizeof(infected));
	infected[start] = true;
	for (auto& i : v)
	{
		if (infected[get<1>(i)])
		{
			if (!check[get<2>(i)])
			{
				return false;
			}
			if (!infected[get<2>(i)]) // 감염 되어야 할놈이 안되어있으면 추가
			{
				cnt++;
				infected[get<2>(i)] = true;
			}
		}
	}
	return (k == cnt);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
	{
		int temp = 0;
		cin >> temp;
		check[temp] = true;
	}
	for (int i = 0; i < m; ++i)
	{
		int time = 0, from = 0, to = 0;
		cin >> time >> from >> to;
		v.push_back(make_tuple(time, from, to));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; ++i)
	{
		if (check[i] && simulation(i))
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}