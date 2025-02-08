#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	getline(cin, str);
	ll cnt = 0, result = 0;
	for (auto& i : str)
	{
		if (i == ')')
		{
			cnt -= 1;
		}
		else if (i == '}')
		{
			cnt -= 2;
		}
		else if (i == ']')
		{
			cnt -= 3;
		}
		else if (i == '(')
		{
			cnt += 1;
		}
		else if (i == '{')
		{
			cnt += 2;
		}
		else if (i == '[')
		{
			cnt += 3;
		}
		else // 숫자면 정산해주기
		{
			result = max(result, cnt);
		}
	}
	cout << result;
	return 0;
}