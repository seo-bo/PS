#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	cout << 1 + (n - 1) * 2 << '\n';
	cout << format("{} {} {} {}\n", 1, n, 1, 1);
	int num = 2, ed = n - 1;
	for (int i = 2; i <= n; ++i)
	{
		int p = n * (i - 1);
		cout << format("{} {} {} {}\n", p + num, p + n, i, 1);
		cout << format("{} {} {} {}\n", p + 1, p + num - 1, i, ed + 1);
		num++;
		ed--;
	}
	return 0;
}