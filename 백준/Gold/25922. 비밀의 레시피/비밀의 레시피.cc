#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	const ll P = 1000000000;
	int n = 0;
	cin >> n;
	cout << format("? {}", P) << endl;
	string str, temp;
	cin >> str;
	int len = str.size();
	cout << "! ";
	vector<ll>ans;
	deque<char>dq;
	auto prt = [&]
		{
			string temp;
			while (!dq.empty())
			{
				temp += dq.front();
				dq.pop_front();
			}
			cout << stoll(temp) << ' ';
		};
	for (int i = len - 1; i >= 0; --i)
	{
		if (dq.size() == 9)
		{
			string temp;
			prt();
		}
		dq.push_front(str[i]);
	}
	prt();
	cout << endl;
}