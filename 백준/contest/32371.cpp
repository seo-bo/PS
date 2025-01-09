#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<string>v(4);
	vector<vector<int>>dir = { {0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };
	for (auto& i : v)
	{
		cin >> i;
	}
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			string temp;
			for (int k = 0; k < 9; ++k)
			{
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				temp += v[nx][ny];
			}
			sort(temp.begin(), temp.end());
			if (temp == str)
			{
				cout << v[i + 1][j + 1];
				return 0;
			}
		}
	}
	return 0;
}
