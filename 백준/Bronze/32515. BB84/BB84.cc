#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	bool check = false;
	vector<char>ans;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == c[i])
		{
			if (b[i] == d[i])
			{
				ans.push_back(b[i]);
			}
			else
			{
				check = true;
				break;
			}
		}
	}
	if (check)
	{
		cout << "htg!";
	}
	else
	{
		for (auto& i : ans)
		{
			cout << i;
		}
	}
	return 0;
}