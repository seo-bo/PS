#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>ba(11, 0), v(11, 1);
	int mul = 1;
	for (auto& i : ba)
	{
		cin >> i;
		mul *= i;
	}
	for (int i = 1; i < 11; ++i)
	{
		v[i] = v[i - 1] * ba[i - 1];
	}
	vector<int>base(mul), day(mul, -1);
	queue<int>q;
	int cnt = 0;
	for (int i = 0; i < mul; ++i)
	{
		cin >> base[i];
		if (base[i] == 1)
		{
			day[i] = 0;
			q.push(i);
		}
		else if (!base[i])
		{
			cnt++;
		}
	}
	if (!cnt)
	{
		cout << 0;
		return 0;
	}
	int ans = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int temp = cur;
		vector<int>pos(11, 0);
		for (int i = 0; i < 11; ++i)
		{
			pos[i] = temp % ba[i];
			temp /= ba[i];
		}
		for (int i = 0; i < 11; ++i)
		{
			if (pos[i] + 1 < ba[i])
			{
				int npos = cur + v[i];
				if (!base[npos] && day[npos] == -1)
				{
					base[npos] = 1;
					day[npos] = day[cur] + 1;
					ans = max(ans, day[npos]);
					q.push(npos);
					cnt--;
				}
			}
			if (pos[i] - 1 >= 0)
			{
				int npos = cur - v[i];
				if (!base[npos] && day[npos] == -1)
				{
					base[npos] = 1;
					day[npos] = day[cur] + 1;
					ans = max(ans, day[npos]);
					q.push(npos);
					cnt--;
				}
			}
		}
	}
	if (cnt)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}