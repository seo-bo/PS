#include <bits/stdc++.h>
#include "bogoSort.h"
using namespace std;

int sc(vector<int>v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] != i)
		{
			return i;
		}
	}
	return -1;
}

void sort_array(int n)
{
	vector<int>v = copy_array();
	while (1)
	{
		int left = sc(v);
		if (left == -1)
		{
			break;
		}
		while (v[left] != left)
		{
			int right = v.size() - 1;
			for (int i = left + 1; i < v.size(); ++i)
			{
				if (v[i] == left)
				{
					right = i;
					break;
				}
			}
			shuffle_array(left, right);
			v = copy_array();
		}
	}
}