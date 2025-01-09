#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str = "";
	cin >> str;
	int size = str.length(), check = 0;
	/****************************************
	일단 처음과 끝이 다르면 전체 팰린드롬 아님
	++ 그냥 반복문 돌려서 확인을 해야하네......
	반례 : ABCBACBCA
	그러면, 처음양옆과 비교해야하나? 중간부터 비교하는게 아니라?
	그러면 -1이 나오는 경우를 찾아봐야한다!
	****************************************/
	for (int i = 0; i < size / 2; ++i)
	{
		if (str[i] != str[size - 1 - i])
		{
			cout << size;
			exit(0);
		}
		if (str[i] != str[i + 1])
		{
			check = 1;
		}
	}
	if (check)
	{
		cout << size - 1;
	}
	else
	{
		cout << -1;
	}
	return 0;
}