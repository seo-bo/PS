#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>ans;
	unordered_set<int>s;
	ans.push_back(n);
	for (int i = 1; i < n; ++i)
	{
		if (s.find(i) == s.end())
		{
			ans.push_back(i);
			s.insert(i);
		}
		if (s.find(n - i) == s.end())
		{
			ans.push_back(n - i);
			s.insert(n - i);
		}
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}