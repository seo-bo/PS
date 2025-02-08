#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

char grid1[30][30];
char grid2[30][30];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arow = 0, acol = 0;
	cin >> arow >> acol;
	for (int i = 0; i < arow; ++i)
	{
		for (int j = 0; j < acol; ++j)
		{
			cin >> grid1[i][j];
		}
	}
	int brow = 0, bcol = 0;
	cin >> brow >> bcol;
	for (int i = 0; i < brow; ++i)
	{
		for (int j = 0; j < bcol; ++j)
		{
			cin >> grid2[i][j];
		}
	}
	int result = INT_MAX;
	for (int i = min(0, 1 - arow); i < brow; ++i)
	{
		for (int j = min(0, 1 - acol); j < bcol; ++j)
		{
			int cnt = 0;
			for (int k = 0; k < brow; ++k)
			{
				for (int z = 0; z < bcol; ++z)
				{
					if (grid2[k][z] == 'O')
					{
						if (k < i || z < j || k >= i + arow || z >= j + acol || grid1[k - i][z - j] != 'O')
						{
							cnt++;
						}
					}
				}
			}
			result = min(result, cnt);
		}
	}
	cout << result;
	return 0;
}
