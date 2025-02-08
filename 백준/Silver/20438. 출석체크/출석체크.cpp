#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<bool>sleep(5005,false);
vector<ll>prefix(5005,1);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N =0, K =0, Q = 0, M = 0;
	cin >> N >> K >> Q >> M;
	for (int i =0; i<K;++i)
	{
		int temp = 0;
		cin >> temp;
		sleep[temp] = true;
	}
	for (int i =0; i<Q;++i)
	{
		int num = 0;
		cin >> num;
		int temp = num;
		if(!sleep[num])
		{
			while(num <= N+2)
			{
				if(sleep[num])
				{
					num += temp;
					continue;
				}
				prefix[num] = 0;
				num += temp;
			}
		}
	}
	prefix[2] = 0;
	for (int i =3; i<=N+2;++i)
	{
		prefix[i] += prefix[i-1];
	}
	for (int i =0; i<M; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		cout << prefix[end] - prefix[start-1] << '\n';
	}
	return 0;
}

