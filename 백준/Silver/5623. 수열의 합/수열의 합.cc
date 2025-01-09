#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

ll ary[1010][1010] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		vector<ll>temp;
		int idx = 0;
		for (int j = 0; j < N; ++j)
		{
			int num = 0;
			cin >> num;
			if (num == 0)
			{
				idx = j;
			}
			temp.push_back(num);
		}
		for (int j = 0; j < N; ++j)
		{
			ary[idx][j] = temp[j];
		}
	}
	vector<ll>result;
	ll a = (ary[0][1] + ary[0][2] - ary[1][2]) / 2;
	result.push_back(a);
	for (int i = 1; i < N; ++i)
	{
		result.push_back(ary[0][i] - a);
	}
	for (auto& i : result)
	{
		cout << i << " ";
	}
	/**********************************
	 0 a+b a+c a+d a+e
	 a+b 0 b+c b+d b+e
	 a+c b+c 0 c+d c+e
	 a+d b+d c+d 0 d+e
	 a+e b+e c+e d+e 0
**************************************/
	return 0;
}
