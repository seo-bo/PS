#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	int siz = s.length(), cnt = 0;
	vector<string>ans;
	for (int i = 0; i < siz; ++i)
	{
		if (s[i] != t[i])
		{
			cnt++;
		}
	}
	for (int _ = 0; _ < cnt; ++_)
	{
		int pivot = -1;
		bool check = false;
		for (int i = 0; i < siz; ++i)
		{
			if (s[i] != t[i])
			{
				if (s[i] > t[i])
				{
					s[i] = t[i];
					ans.push_back(s);
					check = true;
					break;
				}
				else
				{
					pivot = i;
				}
			}
		}
		if (!check)
		{
			s[pivot] = t[pivot];
			ans.push_back(s);
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}
