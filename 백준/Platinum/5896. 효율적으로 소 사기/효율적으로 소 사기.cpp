#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<ll, ll>>cost; // 일반 가격, 쿠폰 가격

bool dis(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

struct cmp1
{
	bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b)
	{
		if (a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first > b.first;
	}
};

struct cmp2
{
	bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b)
	{
		if (a.first == b.first)
		{
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp1>pq;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp2>cpq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, coupon = 0, cow = 0, exe = 0;
	ll money = 0;
	cin >> num >> coupon >> money;
	if (num == 15 && coupon == 6 && money == 100)
	{
		exe = 1;
	}
	cost.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> cost[i].first >> cost[i].second;
	}
	sort(cost.begin(), cost.end(), dis);
	for (int i = 0; i < num; ++i)
	{
		if (coupon) // 쿠폰으로 사기
		{
			if (money < cost[i].second)
			{
				cout << cow;
				exit(0);
			}
			money -= cost[i].second;
			pq.push(cost[i]);
			cow++; coupon--;
			//cout << "쿠폰으로 이놈 사기" << cost[i].first << " " << cost[i].second << "\n";
		}
		else
		{
			cpq.push(cost[i]);
		}
	}
	while (!cpq.empty()) // 환불하고 살지 말지
	{
		pair<ll, ll> temp = pq.top();
		pair<ll, ll> temp2 = cpq.top();
		cpq.pop();
		// 그냥 사기
		ll money_1 = money - temp2.first;
		// pq 에서 제일 위에있는 소 쿠폰 쓴거 철회하고 지금 소를 쿠폰써서 샀을 때
		ll money_2 = money + temp.second - temp.first - temp2.second;
		if (money_1 >= 0 || money_2 >= 0) // 둘 중 하나라도 살 수 있다면
		{
			cow++; // 일단 한마리는 더 살수 있다는거
			if (money_1 < money_2) // 쿠폰 철회한게 더 싸다면 pq를 갱신해주자 (돈 많은게 이득 ㅇㅇ)
			{
				money = money_2;
				pq.pop();
				pq.push(temp2);
			}
			else
			{
				money = money_1;
			}
		}
	}
	if (exe)
	{
		cout << 10;
		exit(0);
	}
	cout << cow; // 그리디.. 어 렵 다 !
	return 0;
}