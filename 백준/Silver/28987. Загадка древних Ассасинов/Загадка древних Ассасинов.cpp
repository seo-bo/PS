#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size() - 1;
	sort(str.rbegin(), str.rend());
	vector<int>mod(3, 0);
	int sum = 0;
	for (auto& i : str)
	{
		int pivot = (i - '0') % 3;
		mod[pivot]++;
		sum = (sum + pivot) % 3;
	}
	auto prt = [&](deque<char>& v)
		{
			for (auto& i : v)
			{
				cout << i;
			}
			exit(0);
		};
	if (sum == 0)
	{
		cout << str;
	}
	else if (sum == 1) // 1을 하나 지우던가 , 2을 두개 지우던가
	{
		if (mod[1] > 0)
		{
			deque<char>ans;
			int cnt = 0;
			for (int i = len; i >= 0; --i)
			{
				int pivot = (str[i] - '0') % 3;
				if (cnt < 1 && pivot == 1)
				{
					cnt++;
					continue;
				}
				ans.push_front(str[i]);
			}
			prt(ans);
		}
		if (mod[2] > 1)
		{
			deque<char>ans;
			int cnt = 0;
			for (int i = len; i >= 0; --i)
			{
				int pivot = (str[i] - '0') % 3;
				if (cnt < 2 && pivot == 2)
				{
					cnt++;
					continue;
				}
				ans.push_front(str[i]);
			}
			prt(ans);
		}
	}
	else if (sum == 2) // 2를 하나 지우던가, 1을 두개 지우던가
	{
		if (mod[2] > 0)
		{
			deque<char>ans;
			int cnt = 0;
			for (int i = len; i >= 0; --i)
			{
				int pivot = (str[i] - '0') % 3;
				if (cnt < 1 && pivot == 2)
				{
					cnt++;
					continue;
				}
				ans.push_front(str[i]);
			}
			prt(ans);
		}
		if (mod[1] > 1)
		{
			deque<char>ans;
			int cnt = 0;
			for (int i = len; i >= 0; --i)
			{
				int pivot = (str[i] - '0') % 3;
				if (cnt < 2 && pivot == 1)
				{
					cnt++;
					continue;
				}
				ans.push_front(str[i]);
			}
			prt(ans);
		}
	}
	return 0;
}
