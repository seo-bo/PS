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
	string a, ans = "-1";
	int k = 0;
	cin >> a >> k;
	unordered_set<string>visited;
	function<void(string, int)> dfs = [&](string str, int cnt)
		{
			if (!cnt)
			{
				ans = max(ans, str);
				return;
			}
			for (int i = 0; i < str.size(); ++i)
			{
				for (int j = i + 1; j < str.size(); ++j)
				{
					if (!i && str[j] == '0')
					{
						continue;
					}
					swap(str[i], str[j]);
					if (visited.find(str + to_string(cnt - 1)) == visited.end())
					{
						visited.insert(str + to_string(cnt - 1));
						dfs(str, cnt - 1);
					}
					swap(str[i], str[j]);
				}
			}
		};
	dfs(a, k);
	cout << ans;
	return 0;
}