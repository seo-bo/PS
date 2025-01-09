#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;

ll updp[100001] = { 0, }, downdp[100001] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	updp[1] = 1; updp[2] = 2, updp[3] = 3, updp[4] = 5;
	downdp[1] = 1; downdp[2] = 2; downdp[3] = 4; downdp[4] = 8;
	for (int i = 5; i <= 100000; ++i)
	{
		updp[i] = (updp[i - 1] + updp[i - 2]) % MOD;
		downdp[i] = (downdp[i - 1] + downdp[i - 2] + downdp[i - 3] + downdp[i - 4]) % MOD;
	}
	int test = 0;
	cin >> test;
	while (test--)
	{
		int num = 0;
		cin >> num;
		cout << (updp[num] * downdp[num]) % MOD << "\n";
	}
	return 0;
}