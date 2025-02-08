#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/******************************************************
https://driip.me/65d9b58c-bf02-44bf-8fba-54d394ed21e0
imos 누적합에 대해서 새로 알게 되었다!
******************************************************/

string S = "";
string temp = "";
int A[2 * 1000010] = { 0, };
ll prefix[2 * 1000010] = { 0, };

void manacher()
{
	int r = 0, p = 0, len = S.length();
	for (int i = 0; i < len; ++i)
	{
		if (i <= r)
		{
			A[i] = min(A[2 * p - i], r - i);
		}
		else
		{
			A[i] = 0;
		}
		while (0 <= i - A[i] - 1 && i + A[i] + 1 < len && S[i - A[i] - 1] == S[i + A[i] + 1])
		{
			A[i]++;
		}
		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
	}
	/******************************************************
				aeea
		 (0 1 2 3 4 5 6 7 8)
	 idx = (1   2   3   4)
	  S = ? a ? e ? e ? a ?
	  A = 0 1 0 1 4 1 0 1 0
	  -> [2 3 3 2]

				aaaaa
		 (0 1 2 3 4 5 6 7 8 9 10)
	 idx = (1   2   3   4   5)
	  S = ? a ? a ? a ? a ? a ?
	  A = 0 1 2 3 4 5 4 3 2 1 0
	  -> [5 8 9 8 5]

	A[i] - 더미문자는 짝수 / 그냥 문자는 홀수
	*********************************************************/
	int siz = temp.length();
	for (int i = 0; i < len; ++i)
	{
		if (S[i] == '?') // 팰린드롬이 홀수일때
		{
			int mid = (i / 2) + 1;
			int start = mid - (A[i] / 2);
			int dec = mid + 1; // 변화량 줄이기 (mid 포함 영향 감소시켜주기)
			int next = mid + (A[i] / 2) + 1; // 팰린드롬 끝나고 나서 팰린드롬 개수가 안변하게 해야하므로
			if (1 <= start && start <= siz)
			{
				prefix[start]++;
			}
			if (1 <= next && next <= siz)
			{
				prefix[next]++;
			}
			if (1 <= dec && dec <= siz)
			{
				prefix[dec] -= 2;
			}
		}
		else // 팰린드롬이 짝수일때 == mid가 존재하지않음
		{
			int start = ((i - A[i]) / 2) + 1;
			int end = start + A[i] + 1; // 끝 + 1
			int left = (i / 2) + 1;
			int right = left + 1;
			if (1 <= start && start <= siz)
			{
				prefix[start]++;
			}
			if (1 <= end && end <= siz)
			{
				prefix[end]++; // 다음 회문의 시작점으로 가능성
			}
			if (1 <= left && left <= siz)
			{
				prefix[left]--; // 팰린드롬 중심이 두 문자 사이에 위치하는 케이스 제외 위해
			}
			if (1 <= right && right <= siz)
			{
				prefix[right]--;
			}
		}
	}
	for (int i = 1; i <= siz; ++i) // 각 위치에서의 개수 변화량
	{
		prefix[i] += prefix[i - 1];
	}
	for (int i = 1; i <= siz; ++i) // 전체 구간 팰린드롬 개수
	{
		prefix[i] += prefix[i - 1];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> temp;
	for (auto& i : temp)
	{
		S += '?';
		S += i;
	}
	S += '?';
	manacher();
	int test = 0;
	cin >> test;
	while (test--)
	{
		int num = 0;
		cin >> num;
		cout << prefix[num] << "\n";
		// 오버플로우 조심;;
	}
	return 0;
}