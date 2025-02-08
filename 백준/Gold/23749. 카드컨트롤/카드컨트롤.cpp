#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	deque<int>v(n * 2);
	for (auto& i : v)
	{
		char temp;
		cin >> temp;
		if (temp == 'O')
		{
			i = 1;
		}
		else
		{
			i = 0;
		}
	}
	deque<int>temp = v;
	set<deque<int>>pivot;
	sort(temp.begin(), temp.end());
	do
	{
		int s1 = 0, s2 = 0, a = 0, b = 0;
		for (int i = 0; i < 2 * n; i += 2)
		{
			a = temp[i], b = temp[i + 1];
			if (a > b)
			{
				s1++;
			}
			else if (a < b)
			{
				s2++;
			}
		}
		if (s1 > s2)
		{
			pivot.insert(temp);
		}
	} while (next_permutation(temp.begin(), temp.end()));
	set<deque<int>>visited;
	queue<pair<deque<int>, int>>q;
	q.push(make_pair(v, 0));
	visited.insert(v);
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		if (pivot.find(a) != pivot.end())
		{
			cout << b;
			return 0;
		}
		for (int i = 1; i < 2 * n; ++i)
		{
			deque<int>tt = a;
			int num = tt[i];
			tt.erase(tt.begin() + i);
			tt.push_front(num);
			if (visited.find(tt) == visited.end())
			{
				visited.insert(tt);
				q.push(make_pair(tt, b + 1));
			}
		}
	}
	return 0;
}