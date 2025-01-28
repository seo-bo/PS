#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(5);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<int>a = { 1,2,3,4,5 };
	if (v == a)
	{
		cout << "No";
		return 0;
	}
	for (int i = 0; i < 4; ++i)
	{
		swap(v[i], v[i + 1]);
		if (v == a)
		{
			cout << "Yes";
			return 0;
		}
		swap(v[i], v[i + 1]);
	}
	cout << "No";
	return 0;
}
