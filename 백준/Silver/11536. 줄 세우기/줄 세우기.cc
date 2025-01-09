#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 하이고,,,,, 패드로 조금만 그려보지 그랬어...
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bool inc = false, dec = false;
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 1; i < n; ++i)
	{
		if (v[i - 1] < v[i])
		{
			inc = true;
		}
		else if (v[i - 1] > v[i])
		{
			dec = true;
		}
	}
	if (inc && dec)
	{
		cout << "NEITHER";
	}
	else if (inc)
	{
		cout << "INCREASING";
	}
	else
	{
		cout << "DECREASING";
	}
	return 0;
}
