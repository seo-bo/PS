#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> cd;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(1000001, 0);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[temp] = 1;
	}
	auto sv = [&](vector<int>& v1, vector<int>& v2)
		{
			int len = 1;
			while (len < (int)v1.size() + (int)v2.size())
			{
				len <<= 1;
			}
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
			vector<cd>aa(v1.begin(), v1.end()), bb(v2.begin(), v2.end());
			aa.resize(len), bb.resize(len);
			fft(aa, 1);
			fft(bb, 1);
			for (int i = 0; i < len; ++i)
			{
				aa[i] *= bb[i];
			}
			fft(aa, -1);
			vector<int>ans(len);
			for (int i = 0; i < len; ++i)
			{
				ans[i] = (int)round(aa[i].real());
			}
			return ans;
		};
	vector<int>res = sv(v, v);
	ll ans = 0;
	for (int i = 1; i <= 1000000; ++i)
	{
		if (v[i])
		{
			ans += (res[2 * i] - 1) / 2;
		}
	}
	cout << ans;
	return 0;
}
