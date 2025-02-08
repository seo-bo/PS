#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>LIS;
vector<int>r_LIS;
int st[300001] = { 0, };
int ary[300001] = { 0, };
int r_ary[300001] = { 0, };
int head = -1;

void Resize(int num)
{
	LIS.resize(num);
	r_LIS.resize(num);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num >> test;
	Resize(num);
	for (int i = 0; i < num; i++)
	{
		cin >> ary[i];
		r_ary[i] = ary[i] * -1;
	}
	st[++head] = ary[0];
	LIS[0] = 1;
	for (int i = 1; i < num; i++)
	{
		int idx = lower_bound(st, st + head, ary[i]) - st;
		if (st[idx] < ary[i])
		{
			st[++head] = ary[i];
			LIS[i] = head + 1;
		}
		else
		{
			st[idx] = ary[i];
			LIS[i] = idx + 1;
		}
	}
	head = -1;
	memset(st, 0, sizeof(st));
	st[++head] = r_ary[num - 1];
	r_LIS[num - 1] = 1;
	for (int i = num - 2; i >= 0; i--)
	{
		int idx = lower_bound(st, st + head, r_ary[i]) - st;
		if (st[idx] < r_ary[i])
		{
			st[++head] = r_ary[i];
			r_LIS[i] = head + 1;
		}
		else
		{
			st[idx] = r_ary[i];
			r_LIS[i] = idx + 1;
		}
	}
	for (int i = 0; i < test; i++)
	{
		int idx = 0;
		cin >> idx;
		cout << LIS[idx - 1] + r_LIS[idx - 1] - 1 << "\n";
	}
	return 0;
}