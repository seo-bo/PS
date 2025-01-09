#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		string temp = "";
		cin >> temp;
		int siz = temp.length();
		int result = 1;
		int check = 0;
		for (int i = 1; i < siz; ++i)
		{
			if (temp[i - 1] != temp[i]) 
			{
				result++;
			}
			else
			{
				continue;
			}
			if (!(temp[i - 1] - '0') && (temp[i] - '0'))
			{
				check = 1;
			}
		}
		cout << result - check << "\n";
	}
	return 0;
}
