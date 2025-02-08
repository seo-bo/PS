#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int left = 1, right = n;
	while (1)
	{
		if (right - left + 1 <= 1)
		{
			break;
		}
		int siz = (right - left + 1) / 3;
		if (right - left + 1 == 2)
		{
			siz = 1;
		}
		vector<int>a, b, c;
		for (int i = left; i < left + siz; ++i)
		{
			a.push_back(i);
		}
		for (int i = left + siz; i < left + 2 * siz; ++i)
		{
			b.push_back(i);
		}
		for (int i = left + 2 * siz; i <= right; ++i)
		{
			c.push_back(i);
		}
		cout << "? ";
		for (auto& i : a)
		{
			cout << i << ' ';
		}
		cout << 0 << ' ';
		for (auto& i : b)
		{
			cout << i << ' ';
		}
		cout << 0 << endl;
		string ans;
		cin >> ans;
		if (ans == "<") // a가 답
		{
			right = left + siz - 1;
		}
		else if (ans == ">") // b가 답
		{
			left = left + siz;
			right = left + siz - 1;
		}
		else // c가 답
		{
			left = left + 2 * siz;
		}
	}
	cout << "! " << left << endl;
	return 0;
}