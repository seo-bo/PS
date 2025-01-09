#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	vector<char>v;
	for (auto& i : str)
	{
		if (i == '(')
		{
			v.push_back(i);
		}
		else
		{
			if (v.empty() || v.back() == ')')
			{
				v.push_back(i);
			}
			else
			{
				v.pop_back();
			}	
		}
	}
	cout << v.size();
	return 0;
}