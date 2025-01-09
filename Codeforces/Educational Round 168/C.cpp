#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		string s;
		cin >> s;
		stack<int> stk;
		int cost = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '_')
			{
				if (!stk.empty() && s[stk.top()] == '(')
				{
					s[i] = ')';
					cost += abs(i - stk.top());
					stk.pop();
				}
				else
				{
					s[i] = '(';
					stk.push(i);
				}
			}
			else
			{
				if (s[i] == '(')
				{
					stk.push(i);
				}
				else
				{
					if (!stk.empty() && s[stk.top()] == '(')
					{
						cost += abs(i - stk.top());
						stk.pop();
					}
					else 
					{
						s[i] = '(';
						stk.push(i);
					}
				}
			}
		}
		cout << cost << '\n';
	}
	return 0;
}
