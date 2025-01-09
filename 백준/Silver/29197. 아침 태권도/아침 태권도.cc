#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

set<lb>border1;
set<lb>border2;
set<lb>border3;
set<lb>border4;
set<lb>center;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, cnt = 0;
	cin >> num;
	lb a = 0, b = 0;
	for (int i = 0; i < num; ++i) // 기울기가 같더라도 사분면은 다를 수 있으니까?
	{
		cin >> a >> b;
		if (a > 0 && b > 0)
		{
			border1.insert(b / a);
		}
		else if (a > 0 && b < 0)
		{
			border2.insert(b / a);
		}
		else if (a < 0 && b > 0)
		{
			border3.insert(b / a);
		}
		else if (a < 0 && b < 0)
		{
			border4.insert(b / a);
		}
		else if (!a && b > 0)
		{
			center.insert(1);
		}
		else if (!a && b < 0)
		{
			center.insert(-1);
		}
		else if (a > 0 && !b)
		{
			center.insert(2);
		}
		else if (a < 0 && !b)
		{
			center.insert(-2);
		}
	}
	cout << border1.size() + border2.size() + border3.size() + border4.size() + center.size();
	return 0;
}