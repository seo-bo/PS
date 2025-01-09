#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void) // 10만자리면 pow함수를 쓸때 오버플로우가 나겠군...
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	ll sum = 0, multi = 1;
	cin >> str;
	int siz = str.length();
	for (int i = 0; i < siz; ++i)
	{	
		if (str[i] == 'O')
		{
			sum = (sum + multi) % MOD;
		}
		multi = (multi * 2) % MOD;
	}
	cout << sum;
	return 0;
}