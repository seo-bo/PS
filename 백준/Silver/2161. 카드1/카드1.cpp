#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int>dq;
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		dq.push_back(i);
	}
	while (dq.size() > 1)
	{
		cout << dq.front() << " ";
		dq.pop_front();
		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}
	cout << dq.front();
	return 0;
}