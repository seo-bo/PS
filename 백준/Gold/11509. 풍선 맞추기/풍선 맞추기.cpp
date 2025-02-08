#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<int, int>mm;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (mm.find(temp) == mm.end())
		{
			ans++;
			mm[temp - 1]++;
		}
		else
		{
			if (--mm[temp] == 0)
			{
				mm.erase(temp);
			}
			mm[temp - 1]++;
		}
	}
	cout << ans;
	return 0;
}