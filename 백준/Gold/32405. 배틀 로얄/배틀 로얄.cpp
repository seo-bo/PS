#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 전부다 체력 100만이고 공격력 1이라고 해도 5~6턴에 끝나는데?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>dps(n + 1, 0);
	vector<int>turn(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> dps[i];
	}
	deque<pii>dq;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		dq.push_back(make_pair(temp, i));
	}
	int dmg = 0;
	while (dq.size() > 1)
	{
		auto [hp, idx] = dq.front();
		dmg += dps[idx];
		turn[idx]++;
		dq.pop_front();
		dq.push_back(make_pair(hp, idx));
		while (dq.size() > 1 && dq.front().second != idx)
		{
			int pivot = dq.front().first - (dmg - turn[dq.front().second] * dps[dq.front().second]);
			if (pivot <= 0)
			{
				dq.pop_front();
			}
			else
			{
				break;
			}
		}
	}
	cout << dq.front().second;
	return 0;
}