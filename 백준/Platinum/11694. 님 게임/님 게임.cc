#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	// 전부다 1이라면 짝홀로 갈림. 그게 아니라면 xor 연산으로 답 내기.
	int n = 0;
	cin >> n;
	int sum = 0;
	bool check = true;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp != 1)
		{
			check = false;
		}
		sum ^= temp;
	}
	if (check)
	{
		if (n % 2)
		{
			cout << "cubelover" << '\n';
		}
		else
		{
			cout << "koosaga" << '\n';
		}
	}
	else
	{
		if (!sum)
		{
			cout << "cubelover" << '\n';
		}
		else
		{
			cout << "koosaga" << '\n';
		}
	}
	return 0;
}