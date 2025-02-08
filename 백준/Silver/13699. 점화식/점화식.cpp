#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<ll>t(n + 5, 0);
	t[0] = 1, t[1] = 1, t[2] = 2, t[3] = 5;
	for (int i = 4; i <= n; ++i)
	{
		int left = 0, right = i - 1;
		while (left != i && right != -1)
		{
			t[i] += t[left] * t[right];
			left++;
			right--;
		}
	}
	cout << t[n];
	return 0;
}