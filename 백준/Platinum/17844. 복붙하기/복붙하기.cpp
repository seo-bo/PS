#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Hashing //https://github.com/seo-bo/Algorithm_templates/blob/main/Hashing.cpp
{
private:
	long long base, MOD, len;
	vector<long long>H, P;
	string str;
	long long mul(long long a, long long b)
	{
		__int128 temp = (__int128)a * b;
		return ((long long)(temp & MOD) + (long long)(temp >> 61LL)) % MOD;
	}
	void cal()
	{
		for (int i = 1; i <= len; ++i)
		{
			P[i] = mul(P[i - 1], base);
			__int128 temp = (__int128)H[i - 1] * base + (unsigned char)str[i - 1];
			H[i] = ((long long)(temp & MOD) + (long long)(temp >> 61LL)) % MOD;
		}
	}
public:
	Hashing(const string& STR) : MOD((1LL << 61) - 1), str(STR), len((int)STR.size())
	{
		len = str.size();
		random_device rd;
		mt19937 engine(rd());
		uniform_int_distribution<long long>dist((1LL << 25), (1LL << 30));
		base = dist(engine);
		H.resize(len + 2, 0);
		P.resize(len + 2, 1);
		cal();
	}
	long long get_hash(int left, int right)
	{
		return (H[right] - mul(H[left - 1], P[right - left + 1]) + MOD) % MOD;
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
	Hashing hash(str);
	ll left = 1, right = 1e6, ans = -1;
	auto cal = [&](ll mid)
		{
			unordered_map<ll, ll>mm;
			for (int i = 1; i + mid - 1 <= len; ++i)
			{
				ll pivot = hash.get_hash(i, i + mid - 1);
				if (mm.find(pivot) == mm.end())
				{
					mm[pivot] = i;
				}
				else
				{
					if (i - mm[pivot] >= mid)
					{
						return true;
					}
				}
			}
			return false;
		};
	while (left <= right)
	{
		ll mid = (left + right) >> 1;
		if (cal(mid))
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