#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<string>token;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	string temp = "";
	getline(cin, str);
	int siz = str.length();
	for (int i = 0; i < siz; ++i)
	{
		if (str[i] == ' ')
		{
			if (temp != "")
			{
				token.push_back(temp);
				temp = "";
			}
		}
		else if (str[i] == '<' || str[i] == '>' || str[i] == '(' || str[i] == ')')
		{
			if (temp != "")
			{
				token.push_back(temp);
				temp = "";
			}
			temp += str[i];
			token.push_back(temp);
			temp = "";
		}
		else if (str[i] == '&')
		{
			if (str[i + 1] == '&' && i + 1 < siz)
			{
				if (temp != "")
				{
					token.push_back(temp);
					temp = "";
				}
				temp += "&&";
				token.push_back(temp);
				temp = "";
				i++;
			}
		}
		else if (str[i] == '|')
		{
			if (str[i + 1] == '|' && i + 1 < siz)
			{
				if (temp != "")
				{
					token.push_back(temp);
					temp = "";
				}
				temp += "||";
				token.push_back(temp);
				temp = "";
				i++;
			}
		}
		else
		{
			temp += str[i];
		}
	}
	if (temp != "")
	{
		token.push_back(temp);
	}
	for (auto& i : token)
	{
		cout << i << " ";
	}
	return 0;
}