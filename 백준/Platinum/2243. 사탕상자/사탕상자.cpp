#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;
typedef long long ll;

ll tree[MAX * 4] = { 0, };

void update(int start, int end, int node, ll idx, ll value)
{
	if (idx < start || idx > end)
	{
		return;
	}
	tree[node] += value;
	if (idx <= start && end <= idx)
	{
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, value);
	update(mid + 1, end, node * 2 + 1, idx, value);
}

ll query(int start, int end, int node, ll sweet)
{
	//if (node <= start && end <= node)
	//{
	//	return start;
	//}
	if (start == end)
	{
		return start;
	}
	int mid = (start + end) / 2;
	if (tree[node * 2] >= sweet) // 왼쪽에 사탕이 있으면
	{
		return query(start, mid, node * 2, sweet);
	}
	else // 왼쪽에 없으면
	{
		return query(mid + 1, end, node * 2 + 1, sweet - tree[node * 2]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		int temp = 0;
		cin >> temp;
		switch (temp)
		{
		case 1:
		{
			ll sweet = 0;
			cin >> sweet;
			ll idx = query(1, MAX, 1, sweet); // 몇번째로 단건지 확인하기
			update(1, MAX, 1, idx, -1); // 사탕을 하나 뺀거니까 -1
			cout << idx << "\n";
			break;
		}
		case 2:
		{
			int idx = 0;
			ll value = 0;
			cin >> idx >> value;
			update(1, MAX, 1, idx, value); // 사탕의 개수를 넘어서 빼는 입력은 없다고 했으니까?
			break;
		}
		}
	}
	return 0;
}