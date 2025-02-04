#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	unordered_map<string, ll>mm;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string a, b, temp;
		cin >> a >> b;
		int cnt = 0;
		bool flag = false;
		for (auto& i : b)
		{
			if (i == '.')
			{
				flag = true;
				continue;
			}
			temp += i;
		}
		mm[a] = stoll(temp);
	}
	string str;
	cin >> str;
	string temp;
	ll ans = 0, ok = 0;
	for (auto& i : str)
	{
		if ('0' <= i && i <= '9')
		{
			if (ok == 0)
			{
				ok = (i - '0');
			}
			else
			{
				ok = ok * 10 + (i - '0');
			}
			continue;
		}
		if (mm.find(temp + i) == mm.end() && mm.find(temp) != mm.end())
		{
			ans += max(ok, 1LL) * mm[temp];
			ok = 0, temp = "";
		}
		temp += i;
	}
	if (mm.find(temp) != mm.end())
	{
		ans += max(ok, 1LL) * mm[temp];
	}
	string res = to_string(ans);
	if (res.size() < 2)
	{
		while (res.size() < 2)
		{
			res += '0';
		}
		cout << "0." << res;
		return 0;
	}
	for (int i = 0; i < (int)res.size() - 2; ++i)
	{
		cout << res[i];
	}
	cout << "." << res.substr(res.size() - 2);
	return 0;
}