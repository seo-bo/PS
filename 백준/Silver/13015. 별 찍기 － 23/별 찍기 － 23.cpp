#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	auto s1 = [&]
		{
			for (int i = 0; i < n; ++i)
			{
				cout << '*';
			}
			for (int i = 0; i < 2 * n - 3; ++i)
			{
				cout << ' ';
			}
			for (int i = 0; i < n; ++i)
			{
				cout << '*';
			}
			cout << '\n';
		};
	auto s2 = [&](int a)
		{
			for (int i = 0; i < a; ++i)
			{
				cout << ' ';
			}
			cout << '*';
			for (int i = 0; i < n - 2; ++i)
			{
				cout << ' ';
			}
			cout << '*';
			if (a != n - 1)
			{
				//1 -> 5 , 2 ->3 , 3 -> 1
				for (int i = 0; i < 2 * (n - 1) - 1 - 2 * a; ++i)
				{
					cout << ' ';
				}
				cout << '*';
			}
			for (int i = 0; i < n - 2; ++i)
			{
				cout << ' ';
			}
			cout << '*';
			cout << '\n';
		};
	s1();
	for (int i = 1; i <= n - 1; ++i)
	{
		s2(i);
	}
	for (int i = n - 2; i >= 1; --i)
	{
		s2(i);
	}
	s1();
	return 0;
}