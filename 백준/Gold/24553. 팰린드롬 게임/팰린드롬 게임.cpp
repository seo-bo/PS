#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	/*
	10일때 선공이 지는데,
	1~9는 팰린드롬 수라서 11 ~ 19면 선공이 이김
	20일때
	10을 먼저 만드는 놈이 지는건데 일단 -11은 ban(후공이 한번에 만들 수 있어서 최적이 아님)
	최대 -9까지 가능하기 때문에 죽었다 깨어나도 선공이 10에 먼저 도달할 수 밖에 없음
	똑같이 21 ~ 29는 팰린드롬 수라 커버가 가능함
	10의 배수?
	*/
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll a = 0;
		cin >> a;
		if (a % 10)
		{
			cout << 0 << '\n';
		}
		else
		{
			cout << 1 << '\n';
		}
	}
	return 0;
}