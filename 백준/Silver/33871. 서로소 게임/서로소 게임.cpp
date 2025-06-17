#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 아; gcd = 1
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (n % 2)
	{
		cout << "Soomin";
		return 0;
	}
	cout << "Song";
	/*
	* 2
	* 3 -> 2
	* 4 -> 3 -> 2
	* 5 -> 2
	* 6 -> 5 -> 
	* 7 -> 2
	* 8 -> 3 -> 2
	* 9 -> 2
	* 10 -> 3 -> 2
	* 11 -> 2
	* 12 -> 5 -> 2
	*/
	return 0;
}