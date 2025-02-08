#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	vector<int>v(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [](const int& a, const int& b)
		{
			return a > b;
		});
	for (int i = 0; i < num - 2; ++i)
	{
		if (v[i] < v[i + 1] + v[i + 2])
		{
			cout << v[i] + v[i + 1] + v[i + 2];
			return 0;
		}
	}
	cout << -1;
}
