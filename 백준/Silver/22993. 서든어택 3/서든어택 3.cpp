#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0, player = 0;
	cin >> num;
	cin >> player;
	vector<ll>v(num - 1, 0);
	for (int i = 0; i < num - 1; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		if (player > i)
		{
			player += i;
		}
		else
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}