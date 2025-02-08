#include <bits/stdc++.h>
using namespace std;

struct Toilet
{
	int idx;
	int day;
	int want;
	int line;
};

struct cmp
{
	bool operator()(const Toilet& a, const Toilet& b) // 근무 일수가 높은 순서 > 화장실에 가고싶은 순서 > 서있는 줄이 작은 순서
	{
		if (a.day == b.day)
		{
			if (a.want == b.want)
			{
				return a.line > b.line;
			}
			return a.want < b.want;
		}
		return a.day < b.day;
	}
};
priority_queue < Toilet, vector<Toilet>, cmp>pq;
queue<Toilet>v[100001]; // 선두를 정해야하는데 vector면 pop.front()안되지않나

void push_and_pop(int num)
{
	if (!v[num].empty())
	{
		pq.push(v[num].front());
		v[num].pop();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, data = 0, index = 0, result = 0;
	cin >> num >> data >> index;
	for (int i = 0; i < num; i++) // 반복문 0부터 시작해서 굳이 index 처리 추가로 안해줘도 될듯
	{
		int tday = 0, twant = 0, temp = 0;
		cin >> tday >> twant;
		temp = i % data; // 줄에 맞추기 위해 나머지 연산
		v[temp].push({ i,tday,twant,temp });
	}
	for (int i = 0; i < data; i++) // 선두 채워주기
	{
		push_and_pop(i);
	}
	while (1)
	{
		Toilet temp = pq.top(); // 우선순위 큐 루트노드 확인
		pq.pop();
		if (temp.idx == index) // 얘가 내가 찾던 그놈이면 정답 출력하고 종료
		{
			cout << result;
			return 0;
		}
		push_and_pop(temp.line); // 라인에 맞춰서 선두 넣어주기
		result++;
	}
}