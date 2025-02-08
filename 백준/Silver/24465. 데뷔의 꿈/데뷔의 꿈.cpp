#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<int, int>Aloha;
//1~365일 까지니까? 윤년까지 계산을 해야하나?
int ary[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int prefix[13] = { 0, };
// 31(1) 60(2) 91(3) 121(4) 152(5) 182(6) 213(7) 244(8) 274(9) 305(10) 335(11) 366(12)
int check(int num)
{
	if (20 <= num && num <= 49) // 물병
	{
		return 1;
	}
	else if (50 <= num && num <= 80) // 물고기
	{
		return 2;
	}
	else if (81 <= num && num <= 110) // 양
	{
		return 3;
	}
	else if (111 <= num && num <= 141) // 황소
	{
		return 4;
	}
	else if (142 <= num && num <= 173) // 쌍둥이
	{
		return 5;
	}
	else if (174 <= num && num <= 204) // 게
	{
		return 6;
	}
	else if (205 <= num && num <= 235) // 사자
	{
		return 7;
	}
	else if (236 <= num && num <= 266) // 처녀
	{
		return 8;
	}
	else if (267 <= num && num <= 296) // 천칭
	{
		return 9;
	}
	else if (297 <= num && num <= 327) // 전갈
	{
		return 10;
	}
	else if (328 <= num && num <= 356) // 사수
	{
		return 11;
	}
	else // 염소
	{
		return 12;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 12; ++i)
	{
		prefix[i] = prefix[i - 1] + ary[i];
	}
	for (int i = 0; i < 7; ++i)
	{
		int month = 0, day = 0;
		cin >> month >> day;
		int temp = check(day + prefix[month - 1]);
		if (Aloha.find(temp) == Aloha.end())
		{
			Aloha.insert({ temp,0 });
		}
	}
	int cnt = 0;
	int num = 0;
	cin >> num;
	vector<pair<int, int>>v(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
		{
			return (a.first == b.first) ? a.second < b.second : a.first < b.first;
		});
	for (auto& i : v)
	{
		int temp = check(i.second + prefix[i.first - 1]);
		if (Aloha.find(temp) == Aloha.end())
		{
			cout << i.first << " " << i.second << "\n";
			cnt++;
		}
	}
	if (!cnt)
	{
		cout << "ALL FAILED";
	}
	return 0;
}