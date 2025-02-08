#include <bits/stdc++.h>
using namespace std;

int ary[1000003] = { 0, };

void prime()
{
	for (int i = 1; i <= 1000003; i++)
	{
		ary[i] = 1;
	}
	for (int i = 2; i <= 500001; i++)
	{
		int divide = i * 2;
		while (divide <= 1000001)
		{
			ary[divide] += i;
			divide += i;
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	prime();
	int test = 1;
	while (1)
	{
		int start = 0, end = 0, term = 0, count = 0;
		cin >> start >> end >> term;
		if (start == 0 && end == 0 && term == 0)
		{
			return 0;
		}
		for (int i = start; i <= end; i++)
		{
			if (abs(i - ary[i]) <= term) 
			{
				count++;
			}
		}
		cout << "Test " << test << ": " << count << "\n";
		test++;
	}
}
