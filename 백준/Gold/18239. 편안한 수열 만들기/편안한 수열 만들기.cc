#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 3번은 아무리 해도 안되는데?
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	if (n == 3)
	{
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	if (n == 2)
	{
		for (int i = 0; i < 5; ++i)
		{
			cout << "swap " << 1 << ' ' << 2 << '\n';
		}
		return 0;
	}
	if (k == 1)
	{
		cout << "swap " << 1 << ' ' << 2 << '\n';
		cout << "reverse " << 2 << ' ' << n << '\n';
		cout << "reverse " << 2 << ' ' << n - 1 << '\n';
		for (int i = 0; i < 2; ++i)
		{
			cout << "reverse " << 1 << ' ' << n << '\n';
		}
	}
	else if (k == n - 1)
	{
		cout << "swap " << 1 << ' ' << n << '\n';
		for (int i = 0; i < 3; ++i)
		{
			cout << "reverse " << 2 << ' ' << n << '\n';
		}
		cout << "reverse " << 3 << ' ' << n << '\n';
	}
	else
	{
		cout << "reverse " << 1 << ' ' << k << '\n';
		cout << "reverse " << k + 1 << ' ' << n << '\n';
		for (int i = 0; i < 3; ++i)
		{
			cout << "reverse " << 1 << ' ' << n << '\n';
		}
	}
	return 0;
}