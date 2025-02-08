#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		string str;
		cin >> str;
		deque<char>s, temp;
		auto cal = [&]
			{
				temp.push_back(s.front());
				s.pop_front();
				if (temp.size() > 2)
				{
					int len = temp.size() - 1;
					if (temp[len] == 'B' && temp[len - 1] == 'B' && temp[len - 2] == 'A')
					{
						for (int k = 0; k < 3; ++k)
						{
							temp.pop_back();
						}
						s.push_front('A');
						s.push_front('B');
					}
				}
			};
		for (auto& i : str)
		{
			s.push_back(i);
		}
		while (!s.empty())
		{
			cal();
		}
		for (auto& i : temp)
		{
			cout << i;
		}
		cout << '\n';
	}
	return 0;
}