#include <bits/stdc++.h>
#define MIN -1e9
#define MAX 1e9
using namespace std;

typedef long long ll;

int ary[100001] = { 0, };
vector<int>tree[100010 * 4];

void init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node].push_back(ary[start]);
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	vector <int>& left = tree[node * 2];
	vector <int>& right = tree[node * 2 + 1];
	tree[node].resize(left.size() + right.size());
	merge(left.begin(), left.end(), right.begin(), right.end(), tree[node].begin());
}

int query(int start, int end, int node, int left, int right, int value)
{
	if (right < start || left > end)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return upper_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin(); // 현재 몇번째 인가?를 반환
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right, value) + query(mid + 1, end, node * 2 + 1, left, right, value);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num >> test;
	for (int i = 1; i <= num; ++i)
	{
		cin >> ary[i];
	}
	init(1, num, 1);
	for (int i = 0; i < test; ++i)
	{
		int start = 0, end = 0, value = 0; //우리가 찾고자 하는 몇번째 값
		cin >> start >> end >> value;
		int ini = MIN, fin = MAX;
		while (ini <= fin)
		{
			int mid = (ini + fin) / 2;
			int key = query(1, num, 1, start, end, mid);
			if (key >= value) // 더 많거나 같으면 상한을 낮추기
			{
				fin = mid - 1;
			}
			else // 더 적으면 하한을 올리기
			{
				ini = mid + 1;
			}
		}
		cout << ini << "\n";
	}
}