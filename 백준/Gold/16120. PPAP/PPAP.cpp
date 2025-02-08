#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	string str;
	cin >> str;
	vector<char>s;
	for (auto& i : str)
	{
		s.push_back(i);
		while (s.size() >= 4)
		{
			string temp;
			for (int k = 0; k < 4; ++k)
			{
				temp += s.back();
				s.pop_back();
			}
			if (temp == "PAPP")
			{
				s.push_back('P');
			}
			else
			{
				for (int k = 0; k < 4; ++k)
				{
					s.push_back(temp.back());
					temp.pop_back();
				}
				break;
			}
		}
	}
	if (s.size() == 1 && s[0] == 'P')
	{
		cout << "PPAP";
	}
	else
	{
		cout << "NP";
	}
	return 0;
}