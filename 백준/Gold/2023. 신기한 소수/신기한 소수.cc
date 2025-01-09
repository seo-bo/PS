#include <bits/stdc++.h>
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
	vector<int>v = { 1,2,3,5,7,9 };
	auto check = [&](string str)
		{
			int num = stoi(str);
			for (int i = 2; i <= sqrt(num); ++i)
			{
				if (!(num % i))
				{
					return false;
				}
			}
			return true;
		};
	function<void(int, string)> dfs = [&](int depth, string str)
		{
			if (depth == n)
			{
				cout << str << '\n';
			}
			for (int i = 0; i < 6; ++i)
			{
				if (!depth && v[i] == 1 || depth && v[i] == 2)
				{
					continue;
				}
				string temp = str;
				temp += (v[i] + '0');
				if (check(temp))
				{
					dfs(depth + 1, temp);
				}
			}
		};
	dfs(0, "");
	return 0;
}