#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, l = 0;
	cin >> n >> l;
	int len = l;
	while (len <= 100)
	{
		int pivot = n - len * (len - 1) / 2;
		if (!(pivot % len)) // 정수인지 확인
		{
			pivot /= len;
			if (pivot >= 0)
			{
				for (int i = 0; i < len; ++i)
				{
					cout << i + pivot << ' ';
				}
				return 0;
			}
		}
			len++;
	}
	cout << -1;
	return 0;
}