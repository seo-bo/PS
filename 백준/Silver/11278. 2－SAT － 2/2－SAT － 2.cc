#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int N = 0, M = 0;
bool check = false;
void dfs(vector<pair<int, int>>& clas, vector<int>& ele)
{
	if (check)
	{
		return;
	}
	if (ele.size() == N)
	{
		int result = 1;
		for (auto& i : clas)
		{
			int num1 = 0;
			int num2 = 0;
			if (i.first < 0)
			{
				num1 = !ele[abs(i.first) - 1];
			}
			else
			{
				num1 = ele[abs(i.first) - 1];
			}
			if (i.second < 0)
			{
				num2 = !ele[abs(i.second) - 1];
			}
			else
			{
				num2 = ele[abs(i.second) - 1];
			}
			result &= (num1 | num2);
			if (!result)
			{
				return;
			}
		}
		check = true;
		cout << 1 << "\n";
		for (auto& i : ele)
		{
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < 2; ++i)
	{
		ele.push_back(i);
		dfs(clas, ele);
		ele.pop_back();
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	vector<pair<int, int>>clas(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> clas[i].first >> clas[i].second;
	}
	vector<int>ele;
	dfs(clas, ele);
	if (!check)
	{
		cout << 0;
	}
	return 0;
}