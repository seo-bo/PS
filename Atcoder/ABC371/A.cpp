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
	char a, b, c;
	cin >> a >> b >> c;
	int aa = 0, bb = 0, cc = 0;
	if (a == '<')
	{
		bb++;
	}
	else
	{
		aa++;
	}
	if (b == '<')
	{
		cc++;
	}
	else
	{
		aa++;
	}
	if (c == '<')
	{
		cc++;
	}
	else
	{
		bb++;
	}
	if ((aa > bb) + (aa > cc) == 1)
	{
		cout << "A";
	}
	else if((bb > aa) + (bb > cc) == 1)
	{
		cout << "B";
	}
	else
	{
		cout << "C";
	}
	return 0;
}
