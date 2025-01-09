#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	k--;
	string bits;
	bits += '0';
	for (int i = 1; i <= 103; ++i)
	{
		string temp = bitset<32>(i).to_string();
		temp = temp.substr(temp.find('1'));
		bits += temp;
	}
	int i = 0;
	queue<char>q;
	for (; i < n; ++i)
	{
		q.push(bits[i]);
	}
	int idx = 0;
	int f = 5;
	while (f)
	{
		if (idx == k)
		{
			cout << q.front() << ' ';
			f--;
		}
		q.pop();
		q.push(bits[i++]);
		idx = (idx + 1) % n;
	}
	return 0;
}