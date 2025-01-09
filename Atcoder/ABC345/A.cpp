#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string temp;
	cin >> temp;
	int size = temp.size();
	if (temp[0] != '<')
	{
		cout << "No";
		return 0;
	}
	if (temp[size - 1] != '>')
	{
		cout << "No";
		return 0;
	}
	for (int i =1; i<size-1;i++)
	{
		if (temp[i] != '=')
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
