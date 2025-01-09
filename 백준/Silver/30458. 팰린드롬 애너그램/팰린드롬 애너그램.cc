#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void) // 처음에 그냥 왼쪽 오른쪽 똑같으면 되는줄 알았는데, 문제를 잘못읽음;
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<int>Alpha(26, 0);
	string str;
	cin >> str;
	for (auto& i : str)
	{
		Alpha[i - 'a']++;
	}
	if (N % 2)
	{
		Alpha[str[N / 2] - 'a']--;
	}
	for (auto& i : Alpha)
	{
		if (i % 2)
		{
			cout << "No";
			exit(0);
		}
	}
	cout << "Yes";
	return 0;
}
