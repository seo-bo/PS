#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, cnt = 0;
		cin >> n;
		vector<char>oper = { ' ','+' ,'-' };
		auto check = [&] (string str)
			{
				ll a = 0;
				bool flag = false;
				string temp, op;
				for (auto& i : str)
				{
					if (i == ' ')
					{
						continue;
					}
					else if (i == '+')
					{
						if (!flag)
						{
							op = "+";
							a = stoll(temp);
							temp = "";
							flag = true;
						}
						else
						{
							if (op == "+")
							{
								a += stoll(temp);
								op = i;
							}
							else if (op == "-")
							{
								a -= stoll(temp);
								op = i;
							}
							temp = "";
						}
					}
					else if (i == '-')
					{
						if (!flag)
						{
							op = "-";
							a = stoll(temp);
							temp = "";
							flag = true;
						}
						else
						{
							if (op == "+")
							{
								a += stoll(temp);
								op = i;
							}
							else if (op == "-")
							{
								a -= stoll(temp);
								op = i;
							}
							temp = "";
						}
					}
					else
					{
						temp += i;
					}
				}
				if (op == "+")
				{
					a += stoll(temp);
				}
				else if (op == "-")
				{
					a -= stoll(temp);
				}
				else
				{
					a = stoll(temp);
				}
				return a;
			};
		function<void(int, string)> dfs = [&](int depth, string ss)
			{
				if (depth == n)
				{
					ss += to_string(depth);
					if (!check(ss))
					{
						cout << ss << '\n';
					}
					return;
				}
				for (int i = 0; i < 3; ++i)
				{
					string temp = ss;
					temp += to_string(depth);
					temp += oper[i];
					dfs(depth + 1, temp);
				}
			};
		dfs(1, "");
		cout << '\n';
	}
	return 0;
}