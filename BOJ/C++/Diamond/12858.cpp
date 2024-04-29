
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>ary, gcdary, tree, lazy, gcdtree; // 양끝만 보면 되는듯? gcd(a,b,c....) = gcd(a,b-a,c-b.....)에 의해??

ll init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = ary[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll GCD_init(int start, int end, int node)
{
	if (start == end)
	{
		return gcdtree[node] = gcdary[start];
	}
	int mid = (start + end) / 2;
	return gcdtree[node] = gcd(GCD_init(start, mid, node * 2), GCD_init(mid + 1, end, node * 2 + 1));
}

void lazy_update(int start, int end, int node)
{
	if (lazy[node])
	{
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int start, int end, int node, int left, int right, ll value)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] += (end - start + 1) * value;
		if (start != end)
		{
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void GCD_update(int start, int end, int node, int idx, int value)
{
	if (idx > end || idx < start)
	{
		return;
	}
	if (idx <= start && end <= idx)
	{
		gcdtree[node] += value;
		return;
	}
	int mid = (start + end) / 2;
	GCD_update(start, mid, node * 2, idx, value);
	GCD_update(mid + 1, end, node * 2 + 1, idx, value);
	gcdtree[node] = gcd(gcdtree[node * 2], gcdtree[node * 2 + 1]);
}


ll query(int start, int end, int node, int idx) // 인덱스 값만 구하기 (gcd(a,b-a...)에서 a찾기 담당)
{
	lazy_update(start, end, node);
	if (idx > end || idx < start)
	{
		return 0;
	}
	if (start == end)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, idx) + query(mid + 1, end, node * 2 + 1, idx);
}

ll GCD_query(int start, int end, int node, int left, int right) // 뒤의값 gcd구하기 담당
{
	if (right < start || end < left)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return gcdtree[node];
	}
	int mid = (start + end) / 2;
	return gcd(GCD_query(start, mid, node * 2, left, right), GCD_query(mid + 1, end, node * 2 + 1, left, right));
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num;
	ary.resize((num + 10));
	gcdary.resize((num + 10));
	tree.resize((num + 10) * 4);
	lazy.resize((num + 10) * 4);
	gcdtree.resize((num + 10) * 4);
	for (int i = 1; i <= num; i++) // 직전값과의 차이를 구하자
	{
		cin >> ary[i];
		if (i == 1)
		{
			continue;
		}
		gcdary[i - 1] = ary[i] - ary[i - 1]; // 1번째를 2번째 - 1번째의 절댓값.....
		// 설마 여기에 절댓값 씌워서 원래 값 훼손 되었기때문에 틀린거라고?
	}
	init(1, num, 1);
	GCD_init(1, num, 1);
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		int temp = 0, start = 0, end = 0;
		cin >> temp >> start >> end;
		switch (temp)
		{
		case 0: // 0이면 쿼리 수행해야함
		{
			cout << gcd(abs(query(1, num, 1, start)), abs(GCD_query(1, num, 1, start, end - 1))) << '\n';
			// gcd(a,b-a,c-b.............) 해야하니 query로 a구하고 GCD_query로 뒤에 있는 gcd 구하기
			break;
		}
		default:
		{
			update(1, num, 1, start, end, temp);
			// 실제로 값을 더하기
			GCD_update(1, num, 1, start - 1, temp);
			// gcdary에 저장된 값은 한발짝 느리다
			GCD_update(1, num, 1, end, -temp);
			// 양끝을 관리해주자
			break;
		}
		}
	}
	return 0;
}
