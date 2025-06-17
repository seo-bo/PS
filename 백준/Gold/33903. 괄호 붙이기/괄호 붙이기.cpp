#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	int alen = A.size(), blen = B.size();
	vector<int>a(alen + 3), prefix(alen + 3), suffix(alen + 3);
	int mini = INT_MAX;
	for (int i = 1; i <= alen; ++i)
	{
		a[i] = a[i - 1] + (A[i - 1] == '(' ? 1 : -1);
		prefix[i] = min(prefix[i - 1], a[i]);
	}
	suffix[alen] = a[alen];
	for (int i = alen - 1; i >= 1; --i)
	{
		suffix[i] = min(suffix[i + 1], a[i]);
	}
	int b = 0;
	for (int i = 1; i <= blen; ++i)
	{
		b = b + (B[i - 1] == '(' ? 1 : -1);
		mini = min(mini, b);
	}
	if (a[alen] + b)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= alen - 1; ++i)
	{
		if (prefix[i] < 0)
		{
			break;
		}
		if (a[i] + mini < 0 || b + suffix[i + 1] < 0)
		{
			continue;
		}
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}