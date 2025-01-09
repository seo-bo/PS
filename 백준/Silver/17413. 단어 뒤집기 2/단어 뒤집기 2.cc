#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str, ans, temp;
	getline(cin, str);
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '<')
		{
			reverse(temp.begin(), temp.end());
			ans += temp;
			temp = "";
			while (str[i] != '>')
			{
				temp += str[i];
				i++;
			}
			ans += (temp + '>');
			temp = "";
		}
		else if (str[i] == ' ')
		{
			reverse(temp.begin(), temp.end());
			ans += temp + ' ';
			temp = "";
		}
		else
		{
			temp += str[i];
		}
	}
	reverse(temp.begin(), temp.end());
	cout << ans + temp;
	return 0;
}