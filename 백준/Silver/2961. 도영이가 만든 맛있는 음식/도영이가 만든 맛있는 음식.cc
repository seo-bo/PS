#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<ll>A;
vector<ll>B;
ll result = LLONG_MAX;
int N = 0;

void dfs(int mask = 0, ll ataste = LLONG_MAX, ll btaste = INT_MAX)
{
	result = min(result, llabs(ataste - btaste));
	if (mask == (1 << N) - 1)
	{
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		if (!(mask & (1 << i)))
		{
			if (!i)
			{
				ataste = 1, btaste = 0;
			}
			dfs(mask |= (1 << i), ataste * A[i], btaste + B[i]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i] >> B[i];
		result = min(llabs(A[i] - B[i]), result);
	}
	if (!result)
	{
		cout << 0;
		return 0;
	}
	dfs();
	cout << result;
	return 0;
}
