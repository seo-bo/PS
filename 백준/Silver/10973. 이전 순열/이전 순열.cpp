#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<int>v;
	bool check = true;
	for (int i = 0; i < N; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp != i + 1)
		{
			check = false;
		}
		v.push_back(temp);
	}
	if (check)
	{
		cout << -1;
		return 0;
	}
	prev_permutation(v.begin(), v.end());
	for (auto& i : v)
	{
		cout << i << " ";
	}
	return 0;
}