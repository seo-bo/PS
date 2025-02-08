#include <bits/stdc++.h>
#include <unordered_map>
#define INF 2000000000
using namespace std;
typedef long long ll;
typedef long double lb;

int siz = 0, result = 0, cnt = 0;
int dis[55][55] = { 0, };

void floyd()
{
	for (int i = 1; i <= siz; ++i)
	{
		for (int j = 1; j <= siz; ++j)
		{
			for (int k = 1; k <= siz; ++k)
			{
				if (dis[j][i] != INF && dis[i][k] != INF && j != k)
				{
					dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> siz;
	char temp;
	for (int i = 1; i <= siz; ++i)
	{	
		for (int j = 1; j <= siz; ++j)
		{
			dis[i][j] = INF;
			cin >> temp;
			if (temp == 'Y')
			{
				dis[i][j] = 1;
			}
		}
	}
	floyd();
	for (int i = 1; i <= siz; ++i)
	{
		cnt = 0;
		for (int j = 1; j <= siz; ++j)
		{
			if (dis[i][j] <= 2)
			{
				cnt++;
			}
		}
		result = max(result, cnt);
	}
	cout << result;
	return 0;
}