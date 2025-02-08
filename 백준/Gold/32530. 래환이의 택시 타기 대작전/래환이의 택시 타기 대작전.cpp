#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		v[i] = stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
	}
	sort(v.begin(), v.end());
	int left = 0, right = 0, ans = 0;
	while (right < n)
	{
		int pivot = v[left];
		int cnt = 0;
		while (right < n && v[right] - pivot <= 20 && cnt < 3)
		{
			right++;
			cnt++;
		}
		ans++;
		left = right;
	}
	cout << ans;
	return 0;
}