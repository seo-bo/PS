#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		unordered_map<char, int>mm;
		int n = 0;
		cin >> n;
		for (int i = 0; i < 4; ++i)
		{
			mm['A' + i] = n;
		}
		string str;
		cin >> str;
		int ans = 0;
		for (auto& i : str)
		{
			if (mm[i])
			{
				ans++;
				mm[i]--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
