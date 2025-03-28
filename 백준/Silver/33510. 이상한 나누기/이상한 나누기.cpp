#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	string str;
	cin >> str;
	deque<int>dq;
	for (auto& i : str)
	{
		dq.push_back(i - '0');
	}
	while (1)
	{
		if (dq.size() == 1 && dq.back() == 1)
		{
			break;
		}
		if (dq.back() & 1)
		{
			ans++;
			int pivot = (dq.back() + 1) / 2;
			dq.pop_back();
			if (dq.empty())
			{
				dq.push_back(pivot);
			}
			else
			{
				int len = dq.size();
				dq[len - 1] += pivot;
			}
		}
		else
		{
			int pivot = dq.back() / 2;
			dq.pop_back();
			if (dq.empty())
			{
				dq.push_back(pivot);
			}
			else
			{
				int len = dq.size();
				dq[len - 1] += pivot;
			}
		}
	}
	cout << ans;
	return 0;
}