#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
typedef long double lb;

vector<int>dest;
int cnt = 0;
map<tuple<int, int, int, int>, int>mm;
void dfs(vector<int>& k, int depth = 0)
{
	if (depth == 4)
	{
		vector<int> minK = k;
		for (int i = 1; i < 4; ++i)
		{
			rotate(k.begin(), k.begin() + i, k.end());
			if (k < minK)
			{
				minK = k;
			}
			rotate(k.begin(), k.end() - i, k.end());
		}
		if (mm[make_tuple(minK[0], minK[1], minK[2], minK[3])] == 0)
		{
			mm[make_tuple(minK[0], minK[1], minK[2], minK[3])]++;
			cnt++;
			if (dest == minK)
			{
				cout << cnt;
				return;
			}
		}
		return;
	}
	for (int i = 1; i <= 9; ++i)
	{
		k.push_back(i);
		dfs(k, depth + 1);
		k.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>v;
	for (int i = 0; i < 4; ++i)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	vector<int> minV = v;
	for (int i = 1; i < 4; ++i)
	{
		rotate(v.begin(), v.begin() + i, v.end());
		if (v < minV)
		{
			minV = v;
		}
		rotate(v.begin(), v.end() - i, v.end());
	}
	dest = minV;
	vector<int>k;
	dfs(k);
	return 0;
}
