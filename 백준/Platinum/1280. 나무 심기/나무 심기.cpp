#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200004

using namespace std;
typedef long long ll;

struct T
{
	ll sum;
	ll index;
};

ll result = 1;
vector<T>tree(MAX * 4, { 0,0 });

void update(int start, int end, int node, ll idx)
{
	if (idx < start || idx > end)
	{
		return;
	}
	if (start == end)
	{
		tree[node].sum += idx;
		tree[node].index++;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx);
	update(mid + 1, end, node * 2 + 1, idx);
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].index = tree[node * 2].index + tree[node * 2 + 1].index;
}

T query(int start, int end, int node, int left, int right)
{
	if (right < start || left > end)
	{
		return { 0,0 };
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	T leftt = query(start, mid, node * 2, left, right);
	T rightt = query(mid + 1, end, node * 2 + 1, left, right);
	return { leftt.sum + rightt.sum, leftt.index + rightt.index };
}

int main(void) // 왼쪽, 오른쪽에 원소가 몇개있는지 알아야함
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, temp = 0;
	cin >> num;
	cin >> temp;
	update(0, MAX - 1, 1, temp);
	for (int i = 1; i < num; ++i)
	{
		ll sum = 0;
		cin >> temp;
		T lefty = query(0, MAX - 1, 1, 0, temp - 1);
		sum += llabs(temp * lefty.index - lefty.sum);
		//cout << "왼쪽 원소 갯수" << lefty.index << "\t";
		T righty = query(0, MAX - 1, 1, temp + 1, MAX - 1);
		sum += llabs(temp * righty.index - righty.sum);
		//cout << "오른쪽 원소 갯수" << righty.index << "\n";
		result = ((result % MOD) * (sum % MOD)) % MOD;
		update(0, MAX - 1, 1, temp);
	}
	cout << result;
	return 0;
}