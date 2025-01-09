#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> ti;

int main(void)
{
	int n = 0;
	cin >> n;
	vector<ti>v(n);
	vector<ll>ans(n,0);
	ll sum = 0;
	for(int i =0; i<n;++i)
	{
		auto & [a,b,c] = v[i];
		cin >> a >> b;
		c = i;
	}
	sort(v.begin(),v.end(), [&] (const ti&a, const ti&b)
	{
		if(get<1>(a) == get<1>(b))
		{
			return get<0>(a) < get<0>(b);
		}
		return get<1>(a) < get<1>(b);
	});
	map<int,ll>color;
	map<int,ll>mm;
	ll temp = 0, pre = -1;
	for(auto & [a,b,c] : v)
	{
		if(b != pre)
		{
			sum += temp;
			temp = 0;
			for(auto & [i,j] : mm)
			{
				color[i] += j; 
			}
			map<int,ll>().swap(mm);
		}
		ans[c] = sum - color[a];
		mm[a] += b;
		temp += b;
		pre = b;
	}
	for(int i =0; i<n;++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}