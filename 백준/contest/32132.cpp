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
	string str, ans;
	cin >> str;
	string temp;
	for (auto& i : str)
	{
		ans += i;
		if (ans.size() >= 3 && (ans.substr(ans.size() - 3) == "PS4" || ans.substr(ans.size() - 3) == "PS5"))
		{
			ans.pop_back();
		}
	}
	cout << ans;
	return 0;
}
