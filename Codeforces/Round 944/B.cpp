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
		int count = 0;
		for (int i = 1; i < siz; ++i)
		{
			if (temp[i] != temp[i - 1])
			{
				swap(temp[i], temp[i - 1]);
				count++;
				break;
			}
		}
		if (count)
		{
			cout << "YES" << "\n";
			cout << temp << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}
