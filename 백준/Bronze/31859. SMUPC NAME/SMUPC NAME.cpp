#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int Alpha[27] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	string temp = "";
	string str = "";
	cin >> num >> temp;
	num += 1906;
	string number = to_string(num);
	int trash = 0;
	for (auto& i : temp)
	{
		if (!(Alpha[i - 'a']))
		{
			str += i;
			Alpha[i - 'a']++;
		}
		else
		{
			trash++;
		}
	}
	trash += 4;
	string tr = to_string(trash);
	string result = number + str + tr;
	cout << "smupc_";
	int siz = result.length();
	for (int i = siz - 1; i >= 0; --i)
	{
		cout << result[i];
	}
}