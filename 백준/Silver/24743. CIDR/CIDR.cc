#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<bitset<32>> v;
	string ip;
	auto ch = [&]()->bitset<32>
		{
			stringstream ss(ip);
			string seg;
			bitset<32> bits;
			int shift = 24;
			while (getline(ss, seg, '.'))
			{
				int b = stoi(seg);
				bits |= (bitset<32>(b) << shift);
				shift -= 8;
			}
			//cout << bits << "\n";
			return bits;
		};
	for (int i = 0; i < n; ++i)
	{
		cin >> ip;
		v.push_back(ch());
	}
	auto search = [&]() -> int
		{
			if (v.empty())
			{
				return 0;
			}
			int cnt = 0;
			bitset<32> common = v[0];
			for (int i = 31; i >= 0; --i)
			{
				for (int j = 1; j < v.size(); ++j)
				{
					if (v[0][i] ^ v[j][i])
					{
						return cnt;
					}
				}
				cnt++;
			}
			return cnt;
		};
	cout << search();
	return 0;
}