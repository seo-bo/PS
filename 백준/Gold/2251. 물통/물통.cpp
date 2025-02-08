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
	set<int>ans;
	set<ti>visited;
	vector<int>v(3);
	for (auto& i : v)
	{
		cin >> i;
	}
	ans.insert(v[2]);
	visited.insert(make_tuple(0, 0, v[2]));
	queue<ti>q;
	q.push(make_tuple(0, 0, v[2]));
	while (!q.empty())
	{
		auto [aa, bb, cc] = q.front();

		q.pop();
		for (int i = 0; i < 3; ++i) // 주는 쪽
		{
			for (int j = 0; j < 3; ++j)// 받는쪽
			{
				if (i == j)
				{
					continue;
				}
				vector<int>temp = { aa,bb,cc };
				if (temp[i] && temp[j] < v[j])
				{
					int pivot = min(temp[i], v[j] - temp[j]);
					temp[i] -= pivot, temp[j] += pivot;
					if (visited.find(make_tuple(temp[0], temp[1], temp[2])) == visited.end())
					{
						visited.insert(make_tuple(temp[0], temp[1], temp[2]));
						q.push(make_tuple(temp[0], temp[1], temp[2]));
						if (temp[0] == 0)
						{
							ans.insert(temp[2]);
						}	
					}
				}
			}
		}
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}