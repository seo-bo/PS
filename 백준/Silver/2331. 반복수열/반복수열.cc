#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, int>m;
	vector<string>v;
	string a;
	int p = 0;
	cin >> a >> p;
	m[a]++;
	v.push_back(a);
	int idx = 0, ans = 0;
	while (1)
	{
		ll sum = 0;
		for (auto& i : v[idx])
		{
			sum += pow(i - '0', p);
		}
		string temp = to_string(sum);
		if (m[temp])
		{
			for (auto& i : v)
			{
				if (i == temp)
				{
					cout << ans;
					return 0;
				}
				ans++;
			}
		}
		m[temp]++;
		v.push_back(temp);
		idx++;
	}
	return 0;
}