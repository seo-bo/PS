#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, player = 0, cnt = 0, maxi = 0, idx = 0;
	cin >> num;
	cin >> player;
	num--;
	if (!num)
	{
		cout << 0;
		return 0;
	}
	vector<int>v(num, 0);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [](const int& a, const int& b)
		{
			return a > b;
		});
	while (1)
	{
		maxi = v[0];
		idx = 0;
		for (int i = 1; i < num; ++i)
		{
			if (v[i] > maxi)
			{
				maxi = v[i];
				idx = i;
			}
		}
		if (player > maxi) // 최댓값 보다 많으니까 매수 끝?
		{
			cout << cnt;
			return 0;
		}
		v[idx]--;
		player++;
		cnt++;
	}
	return 0;
}