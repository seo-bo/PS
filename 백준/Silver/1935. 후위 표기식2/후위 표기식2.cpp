#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	string str;
	vector<int>Alpha(27, 0);
	vector<double>oper;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; ++i)
	{
		cin >> Alpha[i];
	}
	double a = 0, b = 0;
	for (auto& i : str)
	{
		if ('A' <= i && i <= 'Z')
		{
			oper.push_back(Alpha[i - 'A']);
		}
		else
		{
			b = oper.back();
			oper.pop_back();
			a = oper.back();
			oper.pop_back();
			if (i == '*')
			{
				oper.push_back(a * b);
			}
			else if (i == '+')
			{
				oper.push_back(a + b);
			}
			else if (i == '-')
			{
				oper.push_back(a - b);
			}
			else
			{
				oper.push_back(a / b);
			}
		}
	}
	cout << fixed << setprecision(2) << oper.back();
	return 0;
}