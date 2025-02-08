#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	set<int>s;
	for (int i = 0; i < n * n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (s.size() < n)
		{
			s.insert(temp);
		}
		else
		{
			if (temp > *s.begin())
			{
				s.erase(s.begin());
				s.insert(temp);
			}	
		}
	}
	cout << *s.begin();
	return 0;
}