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
	string a, b;
	int dis = 0, n = 0;
	cin >> a >> b >> dis >> n;
	bool male = false, female = false;
	if (b == "FM" || b == "MF")
	{
		male = female = true;
	}
	else if (b == "F")
	{
		female = true;
	}
	else
	{
		male = true;
	}
	vector<string>ans;
	for (int i = 0; i < n; ++i)
	{
		string t1, t2;
		int ag = 0;
		cin >> t1 >> t2 >> ag;
		if (t2 == "F" && female && ag <= dis)
		{
			ans.push_back(t1);
		}
		else if (t2 == "M" && male && ag <= dis)
		{
			ans.push_back(t1);
		}
	}
	if (ans.empty())
	{
		cout << "No one yet";
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}