#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 아 멍청한 놈아 길이가 1일수가없잖아
{
	/*
	둘사이의 거리 ?
	grundy(2) - 0 (할수 있는게 없다..)
	grundy(3) - {0} -> 1
	grundy(4) - {0,1} -> 2
	*/
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<string>ans = { "Whiteking","Blackking" };
	int n = 0;
	cin >> n;
	ll pivot = 0;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		pivot ^= (temp - 2);
	}
	int idx = 0;
	string str;
	cin >> str;
	if (str[0] == 'B')
	{
		idx = 1;
	}
	if (pivot)
	{
		cout << ans[idx];
	}
	else
	{
		cout << ans[(idx + 1) % 2];
	}
	return 0;
}