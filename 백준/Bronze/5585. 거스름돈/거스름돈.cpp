#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, result =0;
	cin >> n;
	n = 1000 - n;
	while (n >= 500)
	{
		n -= 500;
		result++;
	}
	while (n >= 100) 
	{
		n -= 100;
		result++;
	}
	while (n >= 50)
	{
		n -= 50;
		result++;
	}
	while (n >= 10)
	{
		n -= 10;
		result++;
	}
	while (n >= 5)
	{
		n -= 5;
		result++;
	}
	while (n >= 1)
	{
		n -= 1;
		result++;
	}
	cout << result;
	return 0;
}