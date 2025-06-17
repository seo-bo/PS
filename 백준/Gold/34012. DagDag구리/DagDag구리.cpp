#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
아니 생각해보셈... bfs를 돌릴 필요가없음
out이 1인놈은 그거로 경로가 고정이여서 새로 하나를 만들어야 함.
E에 종속적인 정점순으로 그렇게 늘려나가면, 결국에 선행적인 노드가
똑같은 경로를 밟는다고 가정했을때 이미 만들어둔 간선을 밟게 되지 않음?
결론적으로 후순위 노드가 만든 간선이 있으면 선행 노드는 손안쓰고 가능한거고?
그러니까 out이 여러개면 ㄱㅊ은데 out이 1개면 그냥 대놓고 겹치니까 그거만 처리?
*/

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>out(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		out[a]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (out[i] == 1)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}