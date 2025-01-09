#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<char>v(n + 1, '+');
	auto rev = [&](char a)
		{
			if (a == '+')
			{
				return '-';
			}
			else
			{
				return '+';
			}
		};
	bool check = false;
	int idx = -1;
	vector<int>temp;
	for (int i = 2; i <= n; ++i)
	{
		cout << "? 1 * " << i << endl;
		char a;
		cin >> a;
		if (a == '+' && !check)
		{
			check = true;
			idx = i;
		}
		else if (a == '-')
		{
			temp.push_back(i);
		}
		v[i] = a;
	}
	if (check) // +가 들어왔다면?
	{
		cout << "? 1 + " << idx << endl;
		char a;
		cin >> a;
		if (a == '+')
		{
			cout << "! ";
			for (int i = 1; i <= n; ++i)
			{
				cout << v[i] << ' ';
			}
			cout << endl;
		}
		else
		{
			cout << "! ";
			for (int i = 1; i <= n; ++i)
			{
				cout << rev(v[i]) << ' ';
			}
			cout << endl;
		}
	}
	else
	{
		cout << "? " << temp[0] << " + " << temp[1] << endl;
		char a;
		cin >> a;
		if (a == '+')
		{
			cout << "! ";
			for (int i = 1; i <= n; ++i)
			{
				cout << rev(v[i]) << ' ';
			}
			cout << endl;
		}
		else
		{
			cout << "! ";
			for (int i = 1; i <= n; ++i)
			{
				cout << v[i] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}