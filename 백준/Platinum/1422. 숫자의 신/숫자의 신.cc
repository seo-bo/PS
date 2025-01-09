#include <bits/stdc++.h>
using namespace std;

vector<int>v;

bool compare(const int& a, const int& b)
{
	string A = to_string(a) + to_string(b);
	string B = to_string(b) + to_string(a);
	return A > B;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0,cnt = 0, add = 0;
	cin >> num >> cnt;
	v.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i];
		add = max(v[i], add);
	}
	for (int i = 0; i < cnt - num; ++i)
	{
		v.push_back(add);
	}
	sort(v.begin(), v.end(), compare);
	for (auto& i : v)
	{
		cout << i;
	}
	return 0;
}
