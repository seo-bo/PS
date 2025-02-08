#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string n;
	cin >> n;
	vector<int>v(10);
	for (auto& i : n)
	{
		if (i == '9')
		{
			v[6]++;
		}
		else
		{
			v[i - '0']++;
		}
	}
	v[6] = (int)ceil((lb)v[6] / 2);
	cout << *max_element(v.begin(), v.end());
	return 0;
}