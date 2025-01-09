#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

struct sq
{
	ll mul;
	ll plus;
};
vector<int>ary;
vector<ll>tree;
vector<sq>lazy; // first는 곱연산? second는 합연산?

ll init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = ary[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = (init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1)) % MOD;
}

void lazy_update(int start, int end, int node)
{
	if (lazy[node].mul != 1 || lazy[node].plus) // 1을 곱해봤자 == 0을 더해봤자
	{
		tree[node] = ((end - start + 1) * lazy[node].plus + tree[node] * lazy[node].mul) % MOD;
		if (start != end)
		{
			lazy[node * 2].mul = (lazy[node * 2].mul * lazy[node].mul) % MOD;
			lazy[node * 2].plus = (lazy[node * 2].plus * lazy[node].mul + lazy[node].plus) % MOD;
			lazy[node * 2 + 1].mul = (lazy[node * 2 + 1].mul * lazy[node].mul) % MOD;
			lazy[node * 2 + 1].plus = (lazy[node * 2 + 1].plus * lazy[node].mul + lazy[node].plus) % MOD;
		}
		lazy[node].mul = 1;
		lazy[node].plus = 0;
	}
}

void sum_update(int start, int end, int node, int left, int right, ll value) // 1번 쿼리 (더하기), 3번 쿼리 (값 바꿔주기)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] = (tree[node] + (end - start + 1) * value) % MOD;
		if (start != end)
		{
			lazy[node * 2].plus = (lazy[node * 2].plus + value) % MOD;
			lazy[node * 2 + 1].plus = (lazy[node * 2 + 1].plus + value) % MOD;
		}
		return;
	}
	int mid = (start + end) / 2;
	sum_update(start, mid, node * 2, left, right, value);
	sum_update(mid + 1, end, node * 2 + 1, left, right, value);
	tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

void mul_update(int start, int end, int node, int left, int right, ll value) // 2번 쿼리 (곱하기), 3번 쿼리(값 0으로 초기화)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] = (tree[node] * value) % MOD;
		if (start != end)
		{
			lazy[node * 2].mul = (lazy[node * 2].mul * value) % MOD;
			lazy[node * 2].plus = (lazy[node * 2].plus * value) % MOD;
			lazy[node * 2 + 1].mul = (lazy[node * 2 + 1].mul * value) % MOD;
			lazy[node * 2 + 1].plus = (lazy[node * 2 + 1].plus * value) % MOD;
		}
		return;
	}
	int mid = (start + end) / 2;
	mul_update(start, mid, node * 2, left, right, value);
	mul_update(mid + 1, end, node * 2 + 1, left, right, value);
	tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

ll query(int start, int end, int node, int left, int right)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return (query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num;
	ary.resize(num);
	tree.resize(num * 4);
	lazy.resize(num * 4);
	for (int i = 0; i < num * 4; ++i)
	{
		lazy[i].mul = 1;
		lazy[i].plus = 0;
	}
	for (int i = 0; i < num; ++i)
	{
		cin >> ary[i];
	}
	init(0, num - 1, 1);
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		int temp = 0, start = 0, end = 0;
		cin >> temp >> start >> end;
		switch (temp)
		{
		case 1: // (Ai + v) % MOD
		{
			ll value = 0;
			cin >> value;
			sum_update(0, num - 1, 1, start - 1, end - 1, value);
			break;
		}
		case 2: // (Ai * v) % MOD
		{
			ll value = 0;
			cin >> value;
			mul_update(0, num - 1, 1, start - 1, end - 1, value);
			break;
		}
		case 3: // ((Ai * 0) + v) % MOD
		{
			ll value = 0;
			cin >> value;
			mul_update(0, num - 1, 1, start - 1, end - 1, 0);
			sum_update(0, num - 1, 1, start - 1, end - 1, value);
			break;
		}
		case 4:
		{
			cout << (query(0, num - 1, 1, start - 1, end - 1)) % MOD << "\n";
			break;
		}
		}
	}
}