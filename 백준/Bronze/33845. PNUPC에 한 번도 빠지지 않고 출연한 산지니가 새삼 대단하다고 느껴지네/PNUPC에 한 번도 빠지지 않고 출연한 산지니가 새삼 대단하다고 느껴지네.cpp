#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<char>ss;
	string a, b;
	cin >> a >> b;
	for (auto& i : a)
	{
		ss.insert(i);
	}
	for (auto& i : b)
	{
		if (ss.find(i) == ss.end())
		{
			cout << i;
		}
	}
	return 0;
}