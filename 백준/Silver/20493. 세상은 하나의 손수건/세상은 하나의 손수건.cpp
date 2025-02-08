#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int direction[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x = 0, y = 0, N = 0, T = 0, dir = 0, time = 0;
	cin >> N >> T;
	for (int i = 0; i < N; ++i)
	{
		ll temp = 0;
		string str = "";
		cin >> temp >> str;
		x += direction[dir][0] * llabs(time - temp);
		y += direction[dir][1] * llabs(time - temp);
		time = temp;
		if (str == "right")
		{
			dir = (dir + 1) % 4;
		}
		else if (str == "left")
		{
			dir = (dir - 1 + 4) % 4;
		}
	}
	x += direction[dir][0] * llabs(T - time);
	y += direction[dir][1] * llabs(T - time);
	cout << x << " " << y;
	return 0;
}