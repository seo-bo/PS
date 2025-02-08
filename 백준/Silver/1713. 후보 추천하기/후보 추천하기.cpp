#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

map<int, pair<int,int>>vote;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, K = 0;
	cin >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		int num = 0;
		cin >> num;
		if (vote.find(num) != vote.end()) 
		{
			vote[num].second++;
		}
		else if (vote.size() < N)
		{
			vote.insert(make_pair(num,make_pair(i,1)));
		}
		else
		{
			int temp = 0, idx = 100000, count = 100000;
			for (auto& z : vote)
			{
				// 카운트가 작거나, 카운트가 같으면 먼저 들어온놈 제거
				if (z.second.second < count || (z.second.second == count && z.second.first < idx))
				{
					temp = z.first;
					idx = z.second.first;
					count = z.second.second;
				}
			}
			vote.erase(temp);
			vote.insert(make_pair(num, make_pair(i, 1)));
		}
	}
	for (auto& i : vote)
	{
		cout << i.first << " ";
	}
	return 0;
}