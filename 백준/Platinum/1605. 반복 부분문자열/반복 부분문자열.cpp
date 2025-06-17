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

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str;
	cin >> n >> str;
	Hashing hash(str);
	ll left = 1, right = n, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) >> 1;
		bool flag = false;
		unordered_set<ll>ss;
		for (int i = 1; i + mid - 1 <= n; ++i)
		{
			ll pivot = hash.get_hash(i, i + mid - 1);
			if (ss.find(pivot) == ss.end())
			{
				ss.insert(pivot);
				continue;
			}
			flag = true;
			break;
		}
		if (flag)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}