#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

bool isOpposite(int a, int b, int c, int d)
{

	return ((a < c) ^ (a < d)) != ((b < c) ^ (b < d));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;

		a = 2 * a - 1;
		b = 2 * b - 1;
		c = 2 * c - 1;
		d = 2 * d - 1;
		if (isOpposite(a, b, c, d) && isOpposite(c, d, a, b)) 
		{
			cout << "YES" << "\n";
		}
		else 
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}
