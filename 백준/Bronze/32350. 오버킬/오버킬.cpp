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

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, d = 0, p = 0, cnt = 0;
	cin >> n >> d >> p;
	vector<int>v;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		bool flag = false;
		while (v[i] > 0)
		{
			flag = true;
			v[i] -= d;
			cnt++;
		}
		if (flag && v[i] < 0 && i + 1 < n)
		{
			v[i + 1] -= (abs(v[i]) * p) / 100;
		}
	}
	cout << cnt;
	return 0;
}