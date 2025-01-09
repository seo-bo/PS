#include <bits/stdc++.h>
using namespace std;
vector <int>v;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int temp = 0;
	while (1)
	{
		cin >> temp;
		if (temp == 0)
		{
			v.push_back(0);
			break;
		}
		v.push_back(temp);
	}
	reverse(v.begin(), v.end());
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
}
