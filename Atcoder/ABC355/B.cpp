#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> A(N), B(M), C;
	vector<bool> inA(201, false);
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		inA[A[i]] = true;
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> B[i];
	}
	C = A;
	C.insert(C.end(), B.begin(), B.end());
	sort(C.begin(), C.end());
	bool found = false;
	for (int i = 0; i < C.size() - 1; ++i)
	{
		if (inA[C[i]] && inA[C[i + 1]])
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
