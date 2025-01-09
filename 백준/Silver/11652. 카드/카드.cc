#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll, ll>card;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 0;
	cin >> test;
	while (test--)
	{
		ll num = 0;
		cin >> num;
		if (card.find(num) == card.end())
		{
			card.insert({ num,1 });
		}
		else
		{
			card[num] += 1;
		}
	}
	vector<pair<ll, ll>> result(card.begin(), card.end());
	sort(result.begin(), result.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second > b.second;
		});
	cout << result.front().first;
}
