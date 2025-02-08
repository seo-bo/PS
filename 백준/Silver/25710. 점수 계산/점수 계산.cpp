#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	map<int, int>mm;
	vector<int>v;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (mm[temp] < 2)
		{
			v.push_back(temp);
		}
		mm[temp]++;
	}
	int num = 0;
	int siz = v.size();
	for (int i = 0; i < siz; ++i)
	{
		for (int j = i + 1; j < siz; ++j)
		{
			int mul = v[i] * v[j];
			int sum = 0;
			while (mul)
			{
				sum += (mul % 10);
				mul /= 10;
			}
			num = max(sum, num);
		}
	}
	cout << num;
	return 0;
}