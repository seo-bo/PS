#include <bits/stdc++.h>
using namespace std;

vector <int>sum;
vector <int>A;
vector <int>B;
vector <int>C;
vector <int>result;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a = 0, b = 0, c = 0, r = 0;
	cin >> a;
	for (int i = 0; i < a; ++i)
	{
		int temp = 0;
		cin >> temp;
		A.push_back(temp);
	}
	cin >> b;
	for (int i = 0; i < b; ++i)
	{
		int temp = 0;
		cin >> temp;
		B.push_back(temp);
	}
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		int temp = 0;
		cin >> temp;
		C.push_back(temp);
	}
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			sum.push_back(A[i] + B[j]);
		}
	}
	sort(sum.begin(), sum.end());
	cin >> r;
	for (int i = 0; i < r; ++i)
	{
		int temp = 0;
		cin >> temp;
		bool make = false;
		for (int j = 0; j < c && !make; ++j)
		{
			if (binary_search(sum.begin(), sum.end(), temp - C[j]))
			{
				make = true;
			}
		}
		if (make)
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	return 0;
}
