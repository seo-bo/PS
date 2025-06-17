#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Manacher //https://github.com/seo-bo/Algorithm_templates/blob/main/Manacher.cpp
{
private:
	string base;
	ll MOD;
	int len;
	vector<int> solve()
	{
		vector<int>R(len, 0);
		int r = 0, p = 0;
		for (int i = 0; i < len; ++i)
		{
			if (i <= r)
			{
				R[i] = min(R[2 * p - i], r - i);
			}
			while (0 <= i - R[i] - 1 && i + R[i] + 1 < len && base[i - R[i] - 1] == base[i + R[i] + 1])
			{
				R[i]++;
			}
			if (r < i + R[i])
			{
				r = i + R[i];
				p = i;
			}
		}
		return R;
	}
public:
	Manacher(string str)
	{
		base = "?";
		for (auto& i : str)
		{
			base += i;
			base += '?';
		}
		len = base.size();
		MOD = LLONG_MAX;
	}
	Manacher(string str, ll mod) : Manacher(str)
	{
		MOD = mod;
	}
	ll palin()
	{
		vector<int>R = getR();
		ll count = 0;
		for (int i = 0; i < len; ++i)
		{
			count = (count + (R[i] + 1LL) / 2) % MOD;
		}
		return count;
	}
	vector<int> getR()
	{
		return solve();
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	Manacher ans(str);
	vector<int> res = ans.getR();
	int ok = 2 * len - 1, idx = len;
	for (int i = 0; i < res.size(); ++i)
	{
		int left = i - res[i], right = i + res[i];
		if (right >= ok)
		{
			int temp = left / 2;
			if (left % 2 == 0)
			{
				temp = (left + 1) / 2;
			}
			idx = min(idx, temp);
		}
	}
	cout << str;
	string a2 = str.substr(0, idx);
	reverse(a2.begin(), a2.end());
	cout << a2;
	return 0;
}
