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
	int n = 0, d = 0;
	cin >> n;
	vector<int>user(2, 0);
	vector<int>cam(2, 0);
	auto cal = [&](int dir)
		{
			if (dir == 0)
			{
				return make_pair(0, -1);
			}
			if (dir == 1)
			{
				return make_pair(-1, 0);
			}
			if (dir == 2)
			{
				return make_pair(0, 1);
			}
			return make_pair(1, 0);
		};
	pii p = cal(d);
	cam[0] = user[0] + p.first;
	cam[1] = user[1] + p.second;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (str == "MR")
		{
			d = (d + 1) % 4;
			p = cal(d);
			cam[0] = user[0] + p.first;
			cam[1] = user[1] + p.second;
		}
		else if (str == "ML")
		{
			d = (d + 3) % 4;
			p = cal(d);
			cam[0] = user[0] + p.first;
			cam[1] = user[1] + p.second;
		}
		else
		{
			pii pos;
			if (str == "W")
			{
				pos = make_pair(-p.first, -p.second);
			}
			else if (str == "A")
			{
				pos = make_pair(p.second, -p.first);
			}
			else if (str == "S")
			{
				pos = make_pair(p.first, p.second);
			}
			else if (str == "D")
			{
				pos = make_pair(-p.second, p.first);
			}
			user[0] += pos.first;
			user[1] += pos.second;
			cam[0] += pos.first;
			cam[1] += pos.second;
			p = make_pair(cam[0] - user[0], cam[1] - user[1]);
		}
		cout << user[0] << ' ' << user[1] << ' ' << cam[0] << ' ' << cam[1] << '\n';
	}
	return 0;
}