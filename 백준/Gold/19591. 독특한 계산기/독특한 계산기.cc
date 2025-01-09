#include <bits/stdc++.h>
using namespace std;

deque<long long>number;
deque<char>op;
//계산할때마다 pop 3번에 push 1번은 시간이 너무 많이 걸리니 인덱스로 접근하자
long long calculate(long long a, long long b, char op)
{
	switch (op)
	{
		case '+':
		{
			return a + b;
		}
		case '-':
		{
			return a - b;
		}
		case '*':
		{
			return a * b;
		}
		case '/':
		{
			return a / b;
		}
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string get;
	cin >> get;
	int size = get.size();
	for (int i = 0; i < size; i++)
	{
		string temp = "";
		if (i == 0 && get[i] == '-')
		{
			i++;
			while (i < size && !(get[i] == '+' || get[i] == '-' || get[i] == '*' || get[i] == '/'))
			{
				temp.push_back(get[i]);
				i++;
			}
			long long t = stoll(temp);
			number.push_back(-t);
		}
		if (get[i] == '+' || get[i] == '-' || get[i] == '*' || get[i] == '/')
		{
			op.push_back(get[i]);
		}
		else
		{
			while (i < size && !(get[i] == '+' || get[i] == '-' || get[i] == '*' || get[i] == '/'))
			{
				temp.push_back(get[i]);
				i++;
			}
			i--;
			number.push_back(stoll(temp));
		}
	}
	long long left = 0, right = number.size() - 1;
	while (!op.empty())
	{
		if (op.size() == 1)
		{
			long long result = calculate(number[left], number[left + 1], op.front());
			cout << result;
			return 0;
		}
		if ((op.front() == '/' || op.front() == '*') && (op.back() == '+' || op.back() == '-'))
		{
			number[left + 1] = calculate(number[left], number[left + 1], op.front());
			left++;
			op.pop_front();
		}
		else if ((op.front() == '+' || op.front() == '-') && (op.back() == '*' || op.back() == '/'))
		{
			number[right - 1] = calculate(number[right-1], number[right], op.back());
			right--;
			op.pop_back();
		}
		else
		{
			long long L = calculate(number[left], number[left + 1], op.front());
			long long R = calculate(number[right-1], number[right], op.back());
			if (L >= R)
			{
				number[left + 1] = L;
				left++;
				op.pop_front();
			}
			else
			{
				number[right - 1] = R;
				right--;
				op.pop_back();
			}
		}
	}
	cout << number.front();
	return 0;
}
