#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		vector<char>v;
		for (auto& i : str)
		{
			if (v.empty() || v.back() != i)
			{
				v.push_back(i);
			}
			else if (v.back() == i)
			{
				v.pop_back();
			}
		}
		if (v.empty())
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}