#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	getline(cin, str);
	vector<string>v = { "bigdata","public","society" };
	for (auto& i : v)
	{
		if (str.find(i) != string::npos)
		{
			cout << "public bigdata";
			return 0;
		}
	}
	cout << "digital humanities";
	return 0;
}