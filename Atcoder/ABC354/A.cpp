#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tall = 1;
	int n = 0;
	int result = 1;
	cin >> n;
	while (tall <= n)
	{
		tall += pow(2, result);
		result++;
	}
	cout << result;
	return 0;
}
