#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ans, str, check = "UCPC";
	getline(cin, str);
	for (auto& i : str)
	{
		if (check[ans.size()] == i)
		{
			ans += i;
		}
	}
	if (ans == check)
	{
		cout << "I love UCPC";
	}
	else
	{
		cout << "I hate UCPC";
	}
	return 0;
}