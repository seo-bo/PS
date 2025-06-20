#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;
typedef long long ll;
typedef pair<string, ll>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto cal = [&](deque<ll>& dq, pii p)
		{
			auto [str, delta] = p;
			if (str == "NUM")
			{
				dq.push_front(delta);
				return true;
			}
			if (dq.empty())
			{
				return false;
			}
			if (str == "POP")
			{
				dq.pop_front();
			}
			else if (str == "INV")
			{
				dq[0] = -dq[0];
			}
			else if (str == "DUP")
			{
				dq.push_front(dq[0]);
			}
			else
			{
				if (dq.size() == 1)
				{
					return false;
				}
				if (str == "SWP")
				{
					swap(dq[0], dq[1]);
				}
				else if (str == "ADD")
				{
					ll a = dq[0], b = dq[1];
					dq.pop_front();
					dq.pop_front();
					dq.push_front(a + b);

				}
				else if (str == "SUB")
				{
					ll a = dq[0], b = dq[1];
					dq.pop_front();
					dq.pop_front();
					dq.push_front(b - a);
				}
				else if (str == "MUL")
				{
					ll a = dq[0], b = dq[1];
					dq.pop_front();
					dq.pop_front();
					dq.push_front(a * b);
				}
				else if (str == "DIV")
				{
					ll a = dq[0], b = dq[1];
					if (!a)
					{
						return false;
					}
					dq.pop_front();
					dq.pop_front();
					dq.push_front(b / a);
				}
				else if (str == "MOD")
				{
					ll a = dq[0], b = dq[1];
					if (!a)
					{
						return false;
					}
					dq.pop_front();
					dq.pop_front();
					dq.push_front(b % a);
				}
				if (llabs(dq.front()) > MAX)
				{
					return false;
				}
			}
			return true;
		};

	string str;
	vector<vector<ll>>ans;
	while (getline(cin, str))
	{
		if (str.empty())
		{
			continue;
		}
		if (str == "QUIT")
		{
			break;
		}
		vector<pii>oper;
		while (1)
		{
			if (str == "END")
			{
				break;
			}
			if (str.size() == 3)
			{
				oper.push_back(make_pair(str, 0LL));
			}
			else
			{
				stringstream ss(str);
				string pt;
				vector<string>ttt;
				while (ss >> pt)
				{
					ttt.push_back(pt);
				}
				oper.push_back(make_pair(ttt[0], stoll(ttt[1])));
			}
			getline(cin, str);
		}
		cin >> str;
		int n = stoll(str);
		for (int i = 0; i < n; ++i)
		{
			ll a = 0;
			cin >> a;
			deque<ll>dq = { a };
			bool f = true;
			for (auto& j : oper)
			{
				if (!cal(dq, j))
				{
					f = false;
					break;
				}
			}
			if (!f || dq.size() != 1)
			{
				cout << "ERROR" << '\n';
			}
			else
			{
				cout << dq[0] << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}