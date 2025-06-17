#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	set<char>ss;
	for (int i = 0; i < 26; ++i)
	{
		ss.insert(char('a' + i));
	}
	int T = 0;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		string str;
		getline(cin, str);
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		set<char>temp = ss;
		for (auto& i : str)
		{
			temp.erase(i);
		}
		if (temp.empty())
		{
			cout << "pangram\n";
		}
		else
		{
			cout << "missing ";
			for (auto& i : temp)
			{
				cout << i;
			}
			cout << '\n';
		}
	}
	return 0;
}