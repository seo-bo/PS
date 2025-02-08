#include <bits/stdc++.h>
#include <unordered_set>
#define INF INT_MIN
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
	vector<ll>ans;
	for (int i = 0; i <= 9; ++i)
	{
		ans.push_back(i);
	}
	if (ans.size() - 1 >= n)
	{
		cout << ans[n];
		return 0;
	}
	for (int i = 1; i < ans.size(); ++i)
	{
		ll pivot = ans[i], pp = pivot % 10;
		for (int j = 0; j <= 9; ++j)
		{
			if (pp <= j)
			{
				break;
			}
			string str = to_string(pivot);
			str += to_string(j);
			ans.push_back(stoll(str));
		}
	}
	if (ans.size() - 1 < n)
	{
		cout << -1;
		return 0;
	}
	cout << ans[n];
	return 0;
}