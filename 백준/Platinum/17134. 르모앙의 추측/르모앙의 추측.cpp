#include <bits/stdc++.h>
#define P 1000000
using namespace std;
typedef long long ll;
typedef complex<double> cd;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<bool>prime(P + 1, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i * i <= P; ++i)
	{
		if (prime[i])
		{
			for (ll j = i * i; j <= P; j += i)
			{
				prime[j] = false;
			}
		}
	}
	vector<int>odd(P + 1, 0), even(P + 1, 0);
	even[4] = 1;
	for (int i = 3; i <= P; i += 2)
	{
		if (prime[i])
		{
			odd[i] = 1;
			if (i * 2 <= P)
			{
				even[i * 2] = 1;
			}
		}
	}
	auto sv = [&](vector<int>& v1, vector<int>& v2)
		{
			int len = 1;
			while (len < (int)v1.size() + (int)v2.size())
			{
				len <<= 1;
			}
			vector<cd>aa(v1.begin(), v1.end());
			vector<cd>bb(v2.begin(), v2.end());
			aa.resize(len), bb.resize(len);
			auto fft = [&](vector<cd>& v, int pivot)
				{
					for (int i = 1, j = 0; i < len; ++i)
					{
						int bit = len >> 1;
						while (j & bit)
						{
							j ^= bit;
							bit >>= 1;
						}
						j ^= bit;
						if (i < j)
						{
							swap(v[i], v[j]);
						}
					}
					for (int i = 2; i <= len; i <<= 1)
					{
						double angle = 2 * acos(-1.0) * pivot / i;
						cd z(cos(angle), sin(angle));
						for (int j = 0; j < len; j += i)
						{
							cd w(1, 0);
							for (int k = 0; k < i / 2; ++k)
							{
								cd fa = v[j + k];
								cd fb = v[j + k + i / 2] * w;
								v[j + k] = fa + fb;
								v[j + k + i / 2] = fa - fb;
								w *= z;
							}
						}
					}
					if (pivot == -1)
					{
						for (auto& i : v)
						{
							i /= len;
						}
					}
				};
			fft(aa, 1);
			fft(bb, 1);
			for (int i = 0; i < len; ++i)
			{
				aa[i] *= bb[i];
			}
			fft(aa, -1);
			vector<int>ans(len, 0);
			for (int i = 0; i < len; ++i)
			{
				ans[i] = (int)round(aa[i].real());
			}
			return ans;
		};
	vector<int>ans = sv(odd, even);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int temp = 0;
		cin >> temp;
		cout << ans[temp] << '\n';
	}
	return 0;
}