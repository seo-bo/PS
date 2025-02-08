#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<string, int>check;
string temp1, temp2;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, result = 1;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> temp1 >> temp2;
		if (temp1 == temp2)
		{
			continue;
		}
		if (temp1 == "ChongChong")
		{
			if (check.find(temp2) == check.end()) // 없으면
			{
				check.insert(make_pair(temp2, 1));
				result++;
			}
		}
		else if (temp2 == "ChongChong")
		{
			if (check.find(temp1) == check.end())
			{
				check.insert(make_pair(temp1, 1));
				result++;
			}
		}
		else
		{
			if (check.find(temp1) != check.end()) // 있고
			{
				if (check.find(temp2) == check.end()) // 없으면
				{
					check.insert(make_pair(temp2, 1));
					result++;
				}
			}
			else if (check.find(temp2) != check.end()) // 있고
			{
				if (check.find(temp1) == check.end())
				{
					check.insert(make_pair(temp1, 1));
					result++;
				}
			}
		}
		//cout << result << "\n";
	}
	cout << result;
	return 0;
}