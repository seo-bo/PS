#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> cd;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, pivot = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
		pivot = max(pivot, i);
	}
	vector<int>base(pivot + 1, 0);
	for (auto& i : v)
	{
		base[i] = 1;
	}
	auto FFT = [&](vector<cd>& v, int p)
		{
			int len = v.size();
			for (int i = 1, j = 0; i < len; ++i)
			{
				int bit = len >> 1;
				while (bit & j)
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
				double angle = 2 * acos(-1.0) * p / i;
				cd z(cos(angle), sin(angle));
				for (int j = 0; j < len; j += i)
				{
					cd w(1, 0);
					for (int k = 0; k < i / 2; ++k)
					{
						cd fa = v[j + k], fb = v[j + k + i / 2] * w;
						v[j + k] = fa + fb;
						v[j + k + i / 2] = fa - fb;
						w *= z;
					}
				}
			}
			if (p == -1)
			{
				for (auto& i : v)
				{
					i /= len;
				}
			}
		};
	int siz = 1, ss = base.size() + base.size();
	while (siz < ss)
	{
		siz <<= 1;
	}
	vector<cd>aa(base.begin(), base.end()), bb(base.begin(), base.end());
	aa.resize(siz), bb.resize(siz);
	FFT(aa, 1);
	FFT(bb, 1);
	for (int i = 0; i < siz; ++i)
	{
		aa[i] *= bb[i];
	}
	FFT(aa, -1);
	vector<ll>ans(siz);
	for (int i = 0; i < siz; ++i)
	{
		ans[i] = (ll)round(aa[i].real());
	}
	int m = 0, cnt = 0;
	cin >> m;
	while (m--)
	{
		int temp = 0;
		cin >> temp;
		if ((temp <= pivot && base[temp]) || (temp < siz && ans[temp]))
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}