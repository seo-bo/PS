#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>s;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		auto it = lower_bound(s.begin(), s.end(), temp);
		if (it == s.end())
		{
			s.push_back(temp);
		}
		else
		{
			*it = temp;
		}
	}
	cout << s.size();
	return 0;
}