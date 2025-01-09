#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, string>mm;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, cas = 0;
	cin >> num >> cas;
	for (int i = 0; i < num; ++i)
	{
		string temp1, temp2;
		cin >> temp1 >> temp2;
		mm[temp1] = temp2;
	}
	for (int i = 0; i < cas; ++i)
	{
		string temp;
		cin >> temp;
		cout << mm[temp] << "\n";
	}
}