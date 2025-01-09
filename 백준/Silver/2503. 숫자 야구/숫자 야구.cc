#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct bb
{
	string a;
	int b, c;
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<bb>v(n);
	for (auto& i : v)
	{
		cin >> i.a >> i.b >> i.c;
	}
	int ans = 0;
	for (int i = 123; i <= 999; ++i)
	{
		string k = to_string(i);
		if (k.find('0') != string::npos)
		{
			continue;
		}
		if (k[0] == k[1] || k[1] == k[2] || k[0] == k[2])
		{
			continue;
		}
		bool check = true;
		for (int j = 0; j < n; ++j)
		{
			int st = 0, ba = 0;
			for (int z = 0; z < 3; ++z)
			{
				for (int p = 0; p < 3; ++p)
				{
					if (v[j].a[z] == k[p])
					{
						if (z == p)
						{
							st++;
						}
						else
						{
							ba++;
						}	
					}
				}
			}
			if (v[j].b != st || v[j].c != ba)
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}