#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

ll ary[10001] = {0,};
int facto(int num)
{
	if(ary[num])
	{
		return ary[num];
	}
	ary[num] = facto(num-1) * num;
	while(!(ary[num] % 10))
	{
		ary[num] /= 10;
	}
	ary[num] %= 100000;
	return ary[num];
}



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ary[1] = 1;
	ary[2] = 2;
	int N = 0;
	while(cin >> N)
	{
		cout << setw(5) << N << " -> ";
		cout << facto(N) %10 << "\n";
	}
	return 0;
}

