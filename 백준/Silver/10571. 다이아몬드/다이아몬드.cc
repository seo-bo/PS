#include<bits/stdc++.h>
using namespace std;
typedef struct Dia
{
	double w;
	double c;
}Dia;
vector<Dia>ary;
vector<int>dp;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		int num = 0, result = 1;
		cin >> num;
		ary.resize(num + 1);
		dp.resize(num + 1);
		for (int i = 1; i <= num; ++i)
		{
			cin >> ary[i].w >> ary[i].c;
		}
		dp[1] = 1;
		for (int i = 2; i <= num; ++i)
		{
			dp[i] = 1;
			for (int j = 1; j <= i; ++j)
			{
				if (ary[i].w > ary[j].w && ary[i].c < ary[j].c)
				{
					dp[i] = max(dp[i], dp[j] + 1);
					result = max(result, dp[i]);
				}
			}
		}
		cout << result << "\n";
		vector<Dia>().swap(ary);
		vector<int>().swap(dp);
	}
	return 0;
}