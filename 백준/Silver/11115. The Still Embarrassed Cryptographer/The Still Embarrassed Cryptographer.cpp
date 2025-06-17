#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		auto sv = [&]
			{
				string A, B;
				cin >> A >> B;
				int len = A.size();
				map<char, char>mm;
				set<char>ss;
				for (int i = 0; i < len; ++i)
				{
					ss.insert(A[i]);
					ss.insert(B[i]);
					if (mm.find(A[i]) != mm.end())
					{
						if (mm[A[i]] != B[i])
						{
							cout << "mjau";
							return;
						}
						continue;
					}
					mm[A[i]] = B[i];
				}
				int mask = 0;
				ll base = 1;
				for (auto& i : ss)
				{
					if (mm.find(i) == mm.end())
					{
						cout << "mjau";
						return;
					}
					if (mask & (1 << (i - 'A')))
					{
						continue;
					}
					int pivot = 0;
					char x = i;
					do
					{
						if (ss.find(mm[x]) == ss.end())
						{
							cout << "mjau";
							return;
						}
						mask |= (1 << (x - 'A'));
						x = mm[x];
						pivot++;
					} while (x != i);
					base = lcm(base, pivot);
				}
				cout << base - 1;
			};
		sv();
		cout << '\n';
	}
	return 0;
}