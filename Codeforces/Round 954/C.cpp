#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		string str;
		cin >> str;
		vector<int>v(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> v[i];
			v[i]--;
		}
		string temp;
		cin >> temp;
		deque<char>dq;
		sort(temp.begin(), temp.end());
		sort(v.begin(), v.end());
		for (auto& i : temp)
		{
			dq.push_back(i);
		}
		for (int i = 0; i < m; ++i)
		{
			if (i == m - 1 || v[i] != v[i + 1]) // 이거가 연속 되지 않는거니까 무조건 앞에거 붙여버리기?
			{
				str[v[i]] = dq.front();
				dq.pop_front();
			}
			else
			{
				str[v[i]] = dq.back();
				dq.pop_back();
			}
		}
		cout << str << "\n";
	}
	return 0;
}
