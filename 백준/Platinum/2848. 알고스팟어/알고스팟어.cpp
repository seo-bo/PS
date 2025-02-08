#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string temp;
vector<string> str;
vector<int>graph[30];
vector<char>result;
int check[30][30] = { 0, };
int degree[30] = { 0, };
int Alpha[30] = { 0, };
int vertex = 0, q_mark = 0, e_mark = 0; // 정점 ,물음표(접두어), 느낌표(사이클)

void topo()
{
	queue<int>q;
	for (int i = 1; i <= 30; ++i)
	{
		if (Alpha[i])
		{
			vertex++;
			if (!degree[i])
			{
				q.push(i);
			}
		}
	}
	while (!q.empty())
	{
		if (q.size() > 1)
		{
			cout << "?";
			exit(0);
		}
		int current = q.front();
		q.pop();
		result.push_back(current + 'a' - 1);
		for (auto& i : graph[current])
		{
			if (!(--degree[i]))
			{
				q.push(i);
			}
		}
	}
	if (vertex != result.size())
	{
		cout << "!";
		exit(0);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> temp;
		int size = temp.length();
		for (int j = 0; j < size; ++j)
		{
			Alpha[temp[j] - 'a' + 1] = 1;
		}
		str.push_back(temp);
	}
	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = i + 1; j < num; ++j)
		{
			int len = min(str[i].length(), str[j].length());
			int k = 0;
			for (; k < len; ++k)
			{
				if (str[i][k] != str[j][k]) // 다르면 순서가 앞에 있다는거
				{
					int start = str[i][k] - 'a' + 1, end = str[j][k] - 'a' + 1;
					if (!check[start][end]) // 중복안되게 check 배열 사용
					{
						check[start][end] = 1; // 방문처리
						graph[start].push_back(end);
						degree[end]++;
					}
					break;
				}
			}
			if (k == len && str[i].length() > str[j].length())
			{
				cout << "!";
				exit(0);
			}
		}
	}
	topo();
	for (auto& i : result)
	{
		cout << i;
	}
	return 0;
}