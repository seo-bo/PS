#include <bits/stdc++.h>
#include "books.h"
using namespace std;

void solve(int n, int p, int q)
{
	set<int>s;
	int cnt = 0;
	for (int i = 2; cnt < n; i += 2, ++cnt)
	{
		s.insert(i);
	}
	for (int i = 1; i <= n; ++i)
	{
		int pivot = 0;
		if (p > q)
		{
			auto it = s.upper_bound(p);
			--it;
			pivot = answer(*it);
			s.erase(it);
		}
		else if (p < q)
		{
			auto it = s.lower_bound(p);
			pivot = answer(*it);
			s.erase(it);
		}
		p = q;
		q = pivot;
	}
}