#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	vector<int> A(num + 1, 0), B(num + 1, 0), diff(num + 1, 0);
	for (int i = 1; i <= num; ++i)
	{
		cin >> A[i];
		A[i] += A[i - 1];
	}
	for (int i = 1; i <= num; ++i)
	{
		cin >> B[i];
		B[i] += B[i - 1];
	}
	for (int i = 0; i <= num; ++i)
	{
		diff[i] = A[i] - B[i];
	}
	unordered_map<int, long long> count;
	for (int i = 0; i <= num; ++i) 
	{
		count[diff[i]]++;
	}
	long long result = 0;
	for (auto& i : count) 
	{
		long long cnt = i.second;
		result += cnt * (cnt - 1) / 2;
	}
	cout << result;
}
