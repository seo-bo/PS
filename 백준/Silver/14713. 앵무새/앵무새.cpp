#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

queue<string>q[102];
unordered_map<string, int>m;
int N = 0;
ll sum = 0;
void input(int i)
{
	string str = "";
	getline(cin, str);
	int k = 0, siz = str.length();
	string temp = "";
	while (k < str.length())
	{
		if (str[k] == ' ')
		{
			q[i].push(temp);
			if (i)
			{
				m.insert(make_pair(temp, i));
			}
			temp = "";
		}
		else
		{
			temp += str[k];
		}
		k++;
	}
	q[i].push(temp);
	if (i)
	{
		m.insert(make_pair(temp, i));
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++)
	{
		input(i);
		sum += q[i].size();
	}
	input(0);
	if (sum != q[0].size())
	{
		cout << "Impossible";
		return 0;
	}
	while (!q[0].empty())
	{
		auto it = m.find(q[0].front());
		if (it == m.end())
		{
			cout << "Impossible";
			return 0;
		}
		else
		{
			if (q[(*it).second].front() != q[0].front())
			{
				cout << "Impossible";
				return 0;
			}
		}
		q[(*it).second].pop();
		q[0].pop();
	}
	cout << "Possible";
	return 0;
}