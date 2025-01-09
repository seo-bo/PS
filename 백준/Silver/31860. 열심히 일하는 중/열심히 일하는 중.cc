#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

priority_queue<int, vector<int>>pq;
vector<ll>result;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, M = 0, K = 0;
	lb S = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		int temp = 0;
		cin >> temp;
		pq.push(temp);
	}
	while (!pq.empty())
	{
		int top = pq.top();
		pq.pop();
		if (top > K)
		{
			S = (ll)floor(S / 2) + top;
			result.push_back((ll)S);
			top -= M;
			pq.push(top);
		}
	}
	cout << result.size() << "\n";
	for (auto& i : result)
	{
		cout << i << "\n";
	}
}