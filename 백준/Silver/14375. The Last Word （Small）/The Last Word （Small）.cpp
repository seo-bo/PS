#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		string str;
		cin >> str;
		int idx = 1, len = str.size();
		deque<char>dq = { str[0] };
		while (idx < len)
		{
			char pivot = str[idx++];
			if (pivot >= dq.front())
			{
				dq.push_front(pivot);
			}
			else
			{
				dq.push_back(pivot);
			}
		}
		cout << format("Case #{}: ", i);
		for (auto& i : dq)
		{
			cout << i;
		}
		cout << '\n';
	}
	return 0;
}