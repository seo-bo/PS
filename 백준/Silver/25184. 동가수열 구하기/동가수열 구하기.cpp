#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int pivot = n / 2 + 1;
	cout << pivot << ' ';
	for (int i = 1; i < pivot; ++i)
	{
		for (int j = i; j <= n; j += pivot)
		{
			cout << j << ' ';
		}
	}
	return 0;
}