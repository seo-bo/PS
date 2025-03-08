#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	auto query = [&](int a, int b)
		{
			cout << format("? {} {}", a, b) << endl;
			string res;
			cin >> res;
			if (res == "NO")
			{
				return false;
			}
			return true;
		};
	auto power = [&](int a, int b)
		{
			int res = 1;
			for (int i = 1; i <= b; ++i)
			{
				res *= a;
			}
			return res;
		};
	auto search = [&](int num)
		{
			int left = 1, right = 7, res = 0, ok = 8;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (query(ok, ok + MAX / power(num, mid)))
				{
					res = mid;
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
			return 7 - res;
		};
	while (T--)
	{
		int a = search(2), b = search(5);
		int ans = 0, pivot = power(2, a) * power(5, b);
		int left = 0, right = 8;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (query(mid, mid + pivot))
			{
				ans = mid + pivot;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << format("! {}", ans) << endl;
	}
	return 0;
}