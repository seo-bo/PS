#include <bits/stdc++.h>
using namespace std;

vector<string>v;

string reverse(const string temp)
{
	string str = "";
	for (auto& j : temp)
	{
		if (j == '6')
		{
			str = "9" + str;
		}
		else if (j == '9')
		{
			str = "6" + str;
		}
		else
		{
			str = j + str;
		}
	}
	return str;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	v.resize(num);
	string mmax = "";
	for (int i = 0; i < num; i++)
	{
		string temp;
		cin >> temp;
		v[i] = reverse(temp);
		if (mmax.length() < v[i].length())
		{
			mmax = v[i];
		}
		else if (mmax.length() == v[i].length())
		{
			if (mmax < v[i])
			{
				mmax = v[i];
			}
		}
	}
	v.push_back(mmax);
	sort(v.begin(), v.end(), [](const string& A, const string& B)
		{
			return A + B > B + A;
		});
	for (int i = num; i >= 0; i--)
	{
		cout << reverse(v[i]);
	}
	return 0;
}