#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string result = "";
	string str = "";
	string temp = "";
	while (1)
	{
		getline(cin, str);
		for (int i = 0; i < str.length(); ++i)
		{
			if ('A' <= str[i] && str[i] <= 'Z' || 'a' <= str[i] && str[i] <= 'z' || str[i] == '-')
			{
				temp += str[i];
			}
			else
			{
				if (temp != "")
				{
					if (result.length() < temp.length())
					{
						result = temp;
					}
					temp = "";
				}
			}
		}
		if (temp == "E-N-D")
		{
			transform(result.begin(), result.end(), result.begin(), ::tolower);
			cout << result;
			return 0;
		}
	}
	return 0;
}