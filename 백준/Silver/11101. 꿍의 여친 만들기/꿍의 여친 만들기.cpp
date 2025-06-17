#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string a, b, temp;
		cin >> a >> b;
		stringstream s1(a);
		vector<string>o1;
		while (getline(s1, temp, ','))
		{
			o1.push_back(temp);
		}
		map<string, int>mm;
		for (auto& i : o1)
		{
			vector<string>p;
			stringstream s3(i);
			while (getline(s3, temp, ':'))
			{
				p.push_back(temp);
			}
			mm[p[0]] = stoi(p[1]);
		}
		stringstream s2(b);
		vector<string>o2;
		while (getline(s2, temp, '|'))
		{
			o2.push_back(temp);
		}
		int ans = INT_MAX;
		for (auto& i : o2)
		{
			int pivot = 0;
			stringstream s3(i);
			while (getline(s3, temp, '&'))
			{
				pivot = max(pivot, mm[temp]);
			}
			ans = min(ans, pivot);
		}
		cout << ans << '\n';
	}
	return 0;
}