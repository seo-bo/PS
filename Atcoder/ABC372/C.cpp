#include <bits/stdc++.h>
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
	int n = 0, q = 0;
	cin >> n >> q;
	string str;
	cin >> str;
	str = " " + str;
	int cnt = 0;
	for (int i = 1; i <= str.size() - 2; ++i)
	{
		if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C')
		{
			cnt++;
		}
	}
	while (q--)
	{
		int a = 0;
		char b;
		cin >> a >> b;
		vector<int>temp;
		for (int i = -2; i <= 0; ++i)
		{
			int s = a + i;
			if (s >= 1 && s <= n - 2)
			{
				temp.push_back(s);
			}
		}
		for (auto& i : temp)
		{
			if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C')
			{
				cnt--;
			}
		}
		str[a] = b;
		for (auto& i : temp)
		{
			if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C')
			{
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
