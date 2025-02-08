#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

bool Left[400010] = { false, };
vector<int>v;
int w = 0, n = 0;

/***************************************************************************************************
아; 왼쪽 오른쪽 무조건 반으로 나눈다고 되는게 아니라 한쪽 몰빵해야 합이 되는거도 있겠구나;
void left_search(int sum = 0, int depth = 0, int idx = 0)
{
	if (depth == 2)
	{
		Left[sum] = true;
		return;
	}
	if (idx >= n / 2)
	{
		return;
	}
	left_search(sum + v[idx], depth + 1, idx + 1);
	left_search(sum, depth, idx + 1);
}
*************************************************************************************************/

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> w >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	// 일단 수가 겹치면 안된다. 그렇다면? a b ............... c d(n) 면 끝까지갔을때 n-2까지가 left?
	// pivot을 두고 왼쪽 오른쪽 나눠야하나? 수가 겹치면 안되니까? [(1, <i>), (<i+1>, n)] ?
	for (int i = 1; i <= n; ++i) // 1 ~ i = left
	{
		for (int j = 1; j < i; ++j)
		{
			Left[v[i] + v[j]] = true;
		}
		for (int j = i + 2; j <= n; ++j)// i+1 ~ n = right
		{
			int value = v[i + 1] + v[j];
			if (w > value && w - value <= 400000)
			{
				if (Left[w - value])
				{
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}