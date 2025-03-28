#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n+1);
	vector<int>siz, per(n+1);
	for(int i =1; i<=n;++i)
	{
		cin >> v[i];
	}
	int idx = 1, pre = -1, len = 0, ver = 0;
	while(idx <= n)
	{
		if(pre != v[idx])
		{
			siz.push_back(len);
			pre = v[idx];
			ver++;
			len = 1;
		}
		else
		{
			len++;
		}
		per[idx++] = ver;
	}
	siz.push_back(len);
	auto sv = [&] (int pos, int col)
	{
		int od = v[pos];
		v[pos] = col;
		vector<pii>s;
		for(int _ =1; _<=n;++_)
		{
			int i = v[_];
			if(s.empty())
			{
				s.push_back(make_pair(i,1));
				continue;
			}
			if(s.back().first != i)
			{
				while(!s.empty() && s.back().second >= 4)
				{
					s.pop_back();
				}
				if(!s.empty() && s.back().first == i)
				{
					s.back().second++;
				}
				else
				{
					s.push_back(make_pair(i,1));
				}
			}
			else
			{
				s.back().second++;
			}
		}
		while(!s.empty() && s.back().second >= 4)
		{
			s.pop_back();
		}
		v[pos] = od;
		int pivot = 0;
		for(auto & [a,b] : s)
		{
			pivot += b;
		}
		return pivot;
	};
	int ans = n;
	for(int i =1; i<=n;++i)
	{
		if(i - 1 >= 1 && i + 1 <=n && v[i-1] != v[i] && v[i-1] == v[i+1])
		{
			if(siz[per[i-1]] + siz[per[i+1]] + 1 >=4)
			{
				ans = min(ans, sv(i,v[i-1]));
				continue;
			}
		}
		if(i - 1 >=1 && v[i-1] != v[i])
		{
			if(siz[per[i-1]] + 1 >= 4)
			{
				ans = min(ans, sv(i,v[i-1]));
			}
		}
		if(i + 1 <=n && v[i+1] != v[i])
		{
			if(siz[per[i+1]] +1 >= 4)
			{
				ans = min(ans, sv(i,v[i+1]));
			}
		}
	}
	cout << ans;
	return 0;
}