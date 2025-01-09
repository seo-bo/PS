#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

bool not_prime[5000010] = { false, };
int N =0;
void get_prime()
{
	for (int i = 2; i <= sqrt(5000010); ++i)
	{
		if (!not_prime[i])
		{
			for (int j = i * i; j <= 5000010; j += i)
			{
				not_prime[j] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	get_prime();
	deque<char>dq;
	int dir = 0,S =0, B =0;
	dq.push_back('B');
	for (int i =2; i<=N;++i)
	{
		if (!dir)
		{
			if (!(not_prime[i]))
			{
				if (dq.back() == 'B')
				{
					dq.pop_back();
					dq.push_back('S');
				}
				dq.push_back('S');
				dir = (dir+1)%2;
			}
			else
			{
				dq.push_back('B');
			}

		}
		else
		{
				
			if (!(not_prime[i]))
			{
				if (dq.front() == 'B')
				{
					dq.pop_front();
					dq.push_front('S');
				}
				dq.push_front('S');
				dir = (dir+1)%2;

			}
			else
			{

				dq.push_front('B');
			}
		}

	}
	while(!dq.empty())
	{
		if(dq.front() == 'S')
		{
			S++;
		}
		else
		{
			B++;
		}
		dq.pop_front();
	}
	cout << B << ' ' << S;
	return 0;
}
