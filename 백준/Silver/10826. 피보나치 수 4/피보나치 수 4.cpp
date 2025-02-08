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
	if (n < 2)
	{
		n ? cout << 1 : cout << 0;
		return 0;
	}
	auto add = [&](string str1, string str2)->string
		{
			string result = "";
			int i = str1.size() - 1;
			int j = str2.size() - 1;
			int carry = 0;
			while (i >= 0 || j >= 0 || carry)
			{
				int num1 = (i >= 0) ? str1[i--] - '0' : 0;
				int num2 = (j >= 0) ? str2[j--] - '0' : 0;
				int sum = num1 + num2 + carry;
				result += (sum % 10) + '0';
				carry = sum / 10;
			}
			reverse(result.begin(), result.end());
			return result;
		};
	string prev_1 = "1", prev_2 = "0", ans;
	for (int i = 2; i <= n; ++i)
	{
		ans = add(prev_1, prev_2);
		prev_2 = prev_1;
		prev_1 = ans;
	}
	cout << ans;
	return 0;
}