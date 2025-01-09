#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<string, int>hello;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 0, result = 0;
	cin >> test;
	while (test--)
	{
		string temp;
		cin >> temp;
		if (temp == "ENTER")
		{
			unordered_map<string, int>().swap(hello);
		}
		else
		{
			if (hello.find(temp) == hello.end())
			{
				hello.insert(make_pair(temp, 1));
				result++;
			}
		}
	}
	
	cout << result;
}
