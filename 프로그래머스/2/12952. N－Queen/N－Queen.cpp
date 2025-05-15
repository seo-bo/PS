#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>v(n, -1);
	auto check = [&](int depth)
		{
			for (int i = 0; i < depth; ++i)
			{
				if (v[i] == v[depth] || abs(v[depth] - v[i]) == depth - i)
				{
					return false;
				}
			}
			return true;
		};

	function<void(int)> dfs = [&](int depth)
		{
			if (depth == n)
			{
				answer++;
				return;
			}
			for (int i = 0; i < n; ++i)
			{
				v[depth] = i;
				if (check(depth))
				{
					dfs(depth + 1);
				}
			}
		};
	dfs(0);
    return answer;
}