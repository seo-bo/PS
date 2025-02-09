#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> cd;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>temp(n), p(n);
	for (auto& i : temp)
	{
		cin >> i;
	}
	reverse(temp.begin(), temp.end());
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		p.push_back(p[i]);
	}
	auto sv = [&]()
		{
			int siz = 1;
			while (siz < (int)temp.size() + (int)p.size())
			{
				siz <<= 1;
			}
			auto FFT = [&](vector<cd>& base, int pivot)
				{
					int len = base.size();
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
							swap(base[i], base[j]);
						}
					}
					for (int i = 2; i <= len; i <<= 1)
					{
						double angle = 2 * acos(-1.0) / i * pivot;
						cd z(cos(angle), sin(angle));
						for (int j = 0; j < len; j += i)
						{
							cd w(1, 0);
							for (int k = 0; k < i / 2; ++k)
							{
								cd fa = base[j + k], fb = base[j + k + i / 2] * w;
								base[j + k] = fa + fb;
								base[j + k + i / 2] = fa - fb;
								w *= z;
							}
						}
					}
					if (pivot == -1)
					{
						for (auto& i : base)
						{
							i /= len;
						}
					}
				};
			vector<cd>aa(temp.begin(), temp.end()), bb(p.begin(), p.end());
			aa.resize(siz), bb.resize(siz);
			FFT(aa, 1);
			FFT(bb, 1);
			for (int i = 0; i < siz; ++i)
			{
				aa[i] *= bb[i];
			}
			FFT(aa, -1);
			ll res = 0;
			for (int i = 0; i < n; ++i)
			{
				res = max(res, (ll)round(aa[n - 1 + i].real()));
			}
			return res;
		};
	cout << sv();
	return 0;
}