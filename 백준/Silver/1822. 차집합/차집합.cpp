#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
set<int>S;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int A = 0, B = 0;
	cin >> A >> B;
	while (A--)
	{
		int temp = 0;
		cin >> temp;
		S.insert(temp);
	}
	while (B--)
	{
		int temp = 0;
		cin >> temp;
		S.erase(temp);
	}
	if (S.empty())
	{
		cout << 0;
		return 0;
	}
	cout << S.size() << "\n";
	for (auto& i : S)
	{
		cout << i << " ";
	}
}
