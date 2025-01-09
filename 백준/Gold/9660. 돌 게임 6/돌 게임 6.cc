#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	/*
	grundy(0) = 0 => none
	grundy(1) = {0} -> 1 => sk
	grundy(2) = {1} -> 0 => cy
	grundy(3) = {0,0} -> 1 => sk
	grundy(4) = {1,1,0} -> 2 => sk
	grundy(5) = {2,0,1} -> 3 => sk
	grundy(6) = {3,1,0} -> 2 => sk
	grundy(7) = {2,2,1} -> 0 => cy
	grundy(8) = {2,3,0} -> 1 => sk
	grundy(9) = {1,2,3} -> 0 => cy
	*/
	cout << ((n % 7 == 0 || n % 7 == 2) ? "CY" : "SK");
	return 0;
}