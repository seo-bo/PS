#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	cout << -1;
	/*
		단순다각형을 형성하려면 학생들이 원형꼴으로 연결 되어있어야함.
		1번 -> 2번 / 2번 -> 3번....... n-1번 -> n번 / n번 -> 1번 이런식으로

		1번은 2번과 제일 가깝다고 가정할 때 2번에게 쏜다.
		2번은 3번과 제일 가깝다고 가정할 때 3번에게 쏜다.
		n-1번은 n번과 제일 가깝다고 가정할 때 n번에게 쏜다.
		-> n번이 1번에게 총을 쏠 수 있을까??

		n번이 1번에게 가장 가까워야만 총을 쏠 수 있음.
		그러나 1번은 이미 2번에게 총을 쏨. (2번이 1번에게 더 가깝기 때문)
		따라서 n번이 1번 학생에게 가장 가까울수 없다.

		만약 거리가 같다면?
		n번이 1번에게 총을 쏘려면, n번 ~ 1번 거리가 다른 모든 정점 사이의 거리보다 같거나 작아야하지만
		1번 학생은 이미 더 가까운 2번에게 쏘기 때문에 n번이 1번에게 쏠 수 없음
		게다가 거리가 같으면 번호가 더 큰 놈에게 총을 쏴야하므로 n이 1번에게 쏘는 경우는 발생 X

		역순으로 쏜다고 하면?
		2번 -> 1번에서 딜레마가 생긴다.

		다각형을 형성할 수 없다.
	*/
	return 0;
}