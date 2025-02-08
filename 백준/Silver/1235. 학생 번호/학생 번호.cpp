#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void) // 길이가 모두 같다?
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<string>v(N);
	for (int i =0; i<N;++i)
	{
		cin >> v[i];
		reverse(v[i].begin(),v[i].end());
	}
	int siz = v[0].length();
	for (int i =1; i<=siz;++i)
	{
		map<string,int>mm;
		for (auto &j : v)
		{
			mm[j.substr(0,i)]++;
		}		
		if(mm.size() == N)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
