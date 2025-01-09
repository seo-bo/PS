#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0;
	cin >> N;
	vector<string>v(N);
	vector<string>b(N);
	map<char, int>mm;
	mm['B'] = 1; mm['S'] = 2; mm['G'] = 3; mm['P'] = 4; mm['D'] = 5;
	for (int i = 0; i < N; ++i) // 숫자가 낮을수록 어려운거
	{
		cin >> v[i];
		b[i] = v[i];
	}
	sort(v.begin(), v.end(), [&](const string& a, const string& b)
		{
			if (mm[a[0]] == mm[b[0]])
			{
				string it1 = a.substr(1, a.length() - 1);
				string it2 = b.substr(1, b.length() - 1);
				int num1 = stoi(it1);
				int num2 = stoi(it2);
				return num1 > num2;
			}
			return mm[a[0]] < mm[b[0]];
		});
	if (v == b)
	{
		cout << "OK";
		return 0;
	}
	else
	{
		cout << "KO" << "\n";
	}
	for (int i = 0; i < N; ++i)  // b = 원본, v = sorting
	{
		if (v[i] != b[i])
		{
			cout << v[i] << " ";
		}
	}
	return 0;
}
