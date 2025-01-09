#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1)
	{
		vector<int>v(3);
		for (int i = 0; i < 3; ++i)
		{
			cin >> v[i];
		}
		if (!v[0] && !v[1] && !v[2])
		{
			break;
		}
		sort(v.begin(), v.end());
		if (v[2] * v[2] == (v[0] * v[0]) + (v[1] * v[1]))
		{
			cout << "right" << "\n";
		}
		else
		{
			cout << "wrong" << "\n";
		}
	}
	return 0;
}
