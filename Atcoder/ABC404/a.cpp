#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	set<char>s;
	for (char i = 'a'; i <= 'z'; ++i)
	{
		s.insert(i);
	}
	for (auto& i : str)
	{
		s.erase(i);
	}
	cout << *s.begin();	
	return 0;
}
