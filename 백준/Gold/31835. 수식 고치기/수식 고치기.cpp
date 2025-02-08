#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	deque<char>v(n), te;
	char A;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if (i < n - 2)
		{
			te.push_back(v[i]);
		}
	}
	cin >> A;
	if (n == 1)
	{
		if (A == v[0])
		{
			cout << 0;
			return 0;
		}
		else
		{
			cout << 1;
			return 0;
		}
	}
	unordered_map<char, int>mm1;
	unordered_map<int, char>mm2;
	mm1['T'] = 1, mm1['F'] = 0, mm2[1] = 'T', mm2[0] = 'F';
	auto check = [&](char a, char b, char c)
		{
			return (b == '&') ? mm2[mm1[a] & mm1[c]] : mm2[mm1[a] | mm1[c]];
		};
	auto inv = [&](char a)
		{
			if (a == 'T')
			{
				return 'F';
			}
			else if (a == 'F')
			{
				return 'T';
			}
			else if (a == '&')
			{
				return '|';
			}
			else
			{
				return '&';
			}
		};
	while (te.size() >= 3)
	{
		vector<char>a(3);
		for (int i = 0; i < 3; ++i)
		{
			a[i] = te.front();
			te.pop_front();
		}
		te.push_front(check(a[0], a[1], a[2]));
	}
	int ans = INT_MAX;
	if (check(te[0], v[n - 2], v[n - 1]) == A)
	{
		ans = min(ans, 0);
	}
	if (check(te[0], inv(v[n - 2]), v[n - 1]) == A)
	{
		ans = min(ans, 1);
	}
	if (check(te[0], v[n - 2], inv(v[n - 1])) == A)
	{
		ans = min(ans, 1);
	}
	if (check(te[0], inv(v[n - 2]), inv(v[n - 1])) == A)
	{
		ans = min(ans, 2);
	}
	cout << ans;
	return 0;
}