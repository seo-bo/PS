#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (n < 4)
	{
		cout << -1;
		return 0;
	}
	if (n % 2)
	{
		for (int i = 0; i < n - 3; ++i)
		{
			cout << i + 2 << '\n';
		}
		cout << format("{}\n{}\n{}", n, 1, n - 1);
	}
	else
	{
		for (int i = 0; i < n - 2; ++i)
		{
			cout << i + 3 << '\n';
		}
		cout << format("{}\n{}", 1, 2);
	}
	return 0;
}