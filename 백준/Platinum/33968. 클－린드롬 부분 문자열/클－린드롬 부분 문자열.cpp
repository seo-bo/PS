#include <bits/stdc++.h>
#include <random>
using namespace std;
typedef long long ll;

class Hashing //https://github.com/seo-bo/Algorithm_templates/blob/main/Hashing.cpp
{
private:
	long long base, MOD, len;
	vector<long long>H, P;
	string str;
	ll mul(ll a, ll b)
	{
		__int128 temp = (__int128)a * b;
		return ((ll)(temp & MOD) + (ll)(temp >> 61LL)) % MOD;
	}
	void cal()
	{
		for (int i = 1; i <= len; ++i)
		{
			P[i] = mul(P[i - 1], base);
			__int128 temp = (__int128)H[i - 1] * base + (unsigned char)str[i - 1];
			H[i] = ((ll)(temp & MOD) + (ll)(temp >> 61LL)) % MOD;
		}
	}
public:
	Hashing(const string& STR) : MOD((1LL << 61) - 1), str(STR), len((int)STR.size())
	{
		len = str.size();
		random_device rd;
		mt19937 engine(rd());
		uniform_int_distribution<ll>dist((1LL << 25), (1LL << 30));
		base = dist(engine);
		H.resize(len + 2, 0);
		P.resize(len + 2, 1);
		cal();
	}
	ll get_hash(int left, int right)
	{
		return (H[right] - mul(H[left - 1], P[right - left + 1]) + MOD) % MOD;
	}
};

class Manacher //https://github.com/seo-bo/Algorithm_templates/blob/main/Manacher.cpp
{
private:
	vector<ll>base;
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
	Manacher(vector<ll>& str)
	{
		base = { -1 };
		for (auto& i : str)
		{
			base.push_back(i);
			base.push_back(-1);
		}
		len = base.size();
		MOD = LLONG_MAX;
	}
	Manacher(vector<ll>& str, ll mod) : Manacher(str)
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
	int n = 0;
	string str;
	cin >> n >> str;
	Hashing hash(str);
	for (int i = 1; i <= n; ++i)
	{
		ll ans = 0;
		vector<ll>temp;
		for (int j = 1; j + i - 1 <= n; ++j)
		{
			temp.push_back(hash.get_hash(j, j + i - 1));
		}
		for (int j = 0; j < i; ++j)
		{
			vector<ll>ok;
			for (int k = j; k < (int)temp.size(); k += i)
			{
				ok.push_back(temp[k]);
			}
			Manacher pal(ok);
			ans += pal.palin();
		}
		cout << ans << '\n';
	}
	return 0;
}