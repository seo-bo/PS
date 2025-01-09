#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Point
{
public:
	ll x, y;
	static Point pivot;

	static int ccw(const Point& p1, const Point& p2, const Point& p3)
	{
		ll temp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
		temp -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
		if (temp > 0)
		{
			return 1;
		}
		else if (!temp)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	static ll dist(const Point& p1, const Point& p2)
	{
		return (ll)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}

	static bool compare(const Point& p1, const Point& p2)
	{
		int order = ccw(pivot, p1, p2);
		if (!order)
		{
			return dist(pivot, p1) < dist(pivot, p2);
		}
		return order > 0;
	}

	static void Set(vector<Point>&pt)
	{
		pivot = *min_element(pt.begin(), pt.end(), [](const Point& a,Point& b)
			{
				return (a.x == b.x) ? a.y < b.y : a.x < b.x;
			});
	}
};

Point Point::pivot;
vector<Point> v;
int num = 0, cnt = -1;

void convex_hull()
{
	Point::Set(v);
	sort(v.begin(), v.end(), Point::compare);
	/***********************************************************************************
	단순 다각형 문제에 있는 질문 게시판 글을 보고 깨달음.
	반시계 방향으로 정렬하는게 목표인데, pivot으로 부터 시계 ~ 일직선 ~ 반시계으로
	갈 수 밖에 없음. 근데 몇시간 동안 아무리해도 시계방향으로 하면 반시계가 문제,
	반시계면 시계가 문제였음. 왜냐면 일직선 -> 반시계로 돌때 y좌표가 높은 놈이 우선시 되야하니까.
	그러면 차라리 어제 풀었던 방법으로 sort를 해준다음에 끝에서(어쩌피 -1 0 1 순이니까)
	순회하면서 ccw를 재면서 딱 0(일직선포인트) 오기전까지 뒤집어 주면 되지않나라고 생각함
	************************************************************************************/
	while (!Point::ccw(Point::pivot, v[cnt - 1], v[cnt]))
	{
		cnt--;
	}
	reverse(v.begin() + cnt, v.end());
	cout << v.size() << "\n";
	for (auto& i : v)
	{
		cout << i.x << " " << i.y << "\n";
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
		ll px, py;
		char ss;
		cin >> px >> py >> ss;
		if (ss == 'Y')
		{
			v.push_back({ px,py });
			cnt++;
		}
	}
	if (v.size() <= 2)
	{
		cout << 0;
		exit(0);
	}
	convex_hull();
	return 0;
}