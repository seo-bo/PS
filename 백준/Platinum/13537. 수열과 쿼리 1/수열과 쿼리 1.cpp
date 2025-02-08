#include <bits/stdc++.h>
// https://nicotina04.tistory.com/142 보구 공부한 뒤에 혼자 다시짜봤음!!
using namespace std;

int ary[100001] = { 0, };
vector<int> tree[100010 * 4];

void init(int start, int end, int node)
{
	if (start == end)
	{
		//기존 세그의 tree[node] = ary[start]와 유사한듯
		tree[node].push_back(ary[start]);
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1); // 기존세그와 똑같긴하다
	vector<int>& left = tree[node * 2];
	vector<int>& right = tree[node * 2 + 1]; // 왼쪽, 오른쪽 자식들을 벡터에 저장해주기(부분수열)
	tree[node].resize(left.size() + right.size());
	merge(left.begin(), left.end(), right.begin(), right.end(), tree[node].begin());
	// 이 부분이 디게 신기한듯?? 표준 C로는 어떻게 구현해야 할려나...
}

void update(int start, int end, int node, int idx, int value)
{
	if (idx > end || idx < start) // 이것도 기존 세그와 똑같다
	{
		return;
	}
	tree[node].push_back(value);
	// tree[node] += value 같은건가?
	if (idx <= start && end <= idx) // start == end
	{
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, value);
	update(mid + 1, end, node * 2 + 1, idx, value);
}

int query(int start, int end, int node, int left, int right, int value)
{
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		// 이분 탐색으로 인덱스를 반환(전체 - 상한) 
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right, value) + query(mid + 1, end, node * 2 + 1, left, right, value);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i)
	{
		cin >> ary[i];
	}
	init(1, num, 1);
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		int start = 0, end = 0, value = 0;
		cin >> start >> end >> value;
		cout << query(1, num, 1, start, end, value) << "\n";
	}
}