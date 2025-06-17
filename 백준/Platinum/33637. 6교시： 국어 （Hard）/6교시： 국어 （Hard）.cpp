#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int idx[402][402][402]; // 몇번째인지 ?
int pivot[402][402][402];//  남은 시간 얼마인지?
int check[1001][1001]; // 다음 인덱스는 어디?

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	memset(idx, -1, sizeof(idx));
	memset(pivot, -1, sizeof(pivot));
	memset(check, -1, sizeof(check));
	int n = 0, T = 0;
	cin >> n >> T;
	vector<int>_(n), ok(1);
	for (auto& i : _)
	{
		cin >> i;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		ok.push_back(_[i + 1] - _[i] - 1);
	}
	idx[0][0][0] = 1;
	pivot[0][0][0] = ok[1];
	for (int i = n - 2; i >= 1; --i)
	{
		for (int j = 0; j <= 1000; ++j)
		{
			check[i][j] = check[i + 1][j];
			if (ok[i + 1] >= j)
			{
				check[i][j] = i + 1;
			}
		}
	}
	int s = 0, m = 0, e = 0;
	cin >> s >> m >> e;
	vector<int>A(s + 1), B(m + 1), C(e + 1);
	for (int i = 1; i <= s; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> B[i];
	}
	for (int i = 1; i <= e; ++i)
	{
		cin >> C[i];
	}
	int ans = 0;
	for (int i = 0; i <= s; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			for (int k = 0; k <= e; ++k)
			{
				if (idx[i][j][k] == -1)
				{
					continue;
				}
				ans = max(ans, i + j + k);
				if (i + 1 <= s)
				{
					int prob = A[i + 1];
					if (pivot[i][j][k] - prob < 0)
					{
						int it = check[idx[i][j][k]][prob];
						if (it != -1) // 할 수 있는 행동있음
						{
							int nokori = ok[it] - prob;
							if (idx[i + 1][j][k] == -1 || idx[i + 1][j][k] > it || (idx[i + 1][j][k] == it && pivot[i + 1][j][k] < nokori))
							{
								idx[i + 1][j][k] = it;
								pivot[i + 1][j][k] = nokori;
							}
						}
					}
					else
					{
						int nokori = pivot[i][j][k] - prob;
						if (idx[i + 1][j][k] == -1 || idx[i + 1][j][k] > idx[i][j][k] || (idx[i + 1][j][k] == idx[i][j][k] && pivot[i + 1][j][k] < nokori))
						{
							idx[i + 1][j][k] = idx[i][j][k];
							pivot[i + 1][j][k] = nokori;
						}
					}
				}
				if (j + 1 <= m)
				{
					int prob = B[j + 1];
					if (pivot[i][j][k] - prob < 0)
					{
						int it = check[idx[i][j][k]][prob];
						if (it != -1)
						{
							int nokori = ok[it] - prob;
							if (idx[i][j + 1][k] == -1 || idx[i][j + 1][k] > it || (idx[i][j + 1][k] == it && pivot[i][j + 1][k] < nokori))
							{
								idx[i][j + 1][k] = it;
								pivot[i][j + 1][k] = nokori;
							}
						}
					}
					else
					{
						int nokori = pivot[i][j][k] - prob;
						if (idx[i][j + 1][k] == -1 || idx[i][j + 1][k] > idx[i][j][k] || (idx[i][j + 1][k] == idx[i][j][k] && pivot[i][j + 1][k] < nokori))
						{
							idx[i][j + 1][k] = idx[i][j][k];
							pivot[i][j + 1][k] = nokori;
						}
					}
				}
				if (k + 1 <= e)
				{
					int prob = C[k + 1];
					if (pivot[i][j][k] - prob < 0)
					{
						int it = check[idx[i][j][k]][prob];
						if (it != -1)
						{
							int nokori = ok[it] - prob;
							if (idx[i][j][k + 1] == -1 || idx[i][j][k + 1] > it || (idx[i][j][k + 1] == it && pivot[i][j][k + 1] < nokori))
							{
								idx[i][j][k + 1] = it;
								pivot[i][j][k + 1] = nokori;
							}
						}
					}
					else
					{
						int nokori = pivot[i][j][k] - prob;
						if (idx[i][j][k + 1] == -1 || idx[i][j][k + 1] > idx[i][j][k] || (idx[i][j][k + 1] == idx[i][j][k] && pivot[i][j][k + 1] < nokori))
						{
							idx[i][j][k + 1] = idx[i][j][k];
							pivot[i][j][k + 1] = nokori;
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}