#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	/*
	Mex(0) = 0
	Mex(1) = {0} -> 1
	Mex(2) = 0
	Mex(3) = {0,1} -> 2
	Mex(4) = {0} -> 1
	Mex(5) = {2,1,0} -> 3
	Mex(6) = {1,0} -> 2
	Mex(7) = {3,2,1,0} -> 4
	Mex(8) = {2,1,0} -> 3
	Mex(9) = {4,3,2,1,0} -> 5
	Mex(10) = {3,2,1,0} -> 4
	*/
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll pivot = 0;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0, mex = 0;
		cin >> temp;
		mex = (temp % 2) ? (temp + 1) / 2 : (temp - 1) / 2;
		pivot ^= mex;
	}
	if (pivot)
	{
		cout << "koosaga";
	}
	else
	{
		cout << "cubelover";
	}
	return 0;
}