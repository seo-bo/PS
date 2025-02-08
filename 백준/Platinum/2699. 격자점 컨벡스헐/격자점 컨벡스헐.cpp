#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Point
{
public:
	int x, y;
	static Point pivot;

	static ll dist(const Point& p1, const Point& p2)
	{
		return (ll)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}

	static int ccw(const Point& p1, const Point& p2, const Point& p3)
	{
		ll temp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
		temp -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
		if (temp > 0)
		{
			return -1;
		}
		else if (!temp)
		{
			return 0;
		}
		return 1;
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

	static void Set(vector<Point>& pt)
	{
		pivot = *min_element(pt.begin(), pt.end(), [](const Point& a, const Point& b)
			{
				return a.y == b.y ? a.x < b.x : a.y > b.y;
			});
	}
};

Point Point::pivot;
vector<Point> v;
int num = 0;

void convex_hull()
{
	if (v.size() <= 1)
	{
		cout << 1 << "\n";
		cout << v[0].x << " " << v[0].y;
		return;
	}
	vector<Point> s;
	Point::Set(v);
	sort(v.begin(), v.end(), Point::compare);
	s.push_back(v[0]);
	s.push_back(v[1]);
	int size = v.size();
	for (int i = 2; i < size; ++i)
	{
		while (s.size() >= 2)
		{
			Point second = s.back();
			s.pop_back();
			Point first = s.back();
			if (Point::ccw(first, second, v[i]) > 0)
			{
				s.push_back(second);
				break;
			}	
		}
		s.push_back(v[i]);
	}
	cout << s.size() << "\n";
	for (auto& i : s)
	{
		cout << i.x << " " << i.y << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		cin >> num;
		v.resize(num);
		for (int i = 0; i < num; ++i)
		{
			cin >> v[i].x >> v[i].y; 
		}
		convex_hull();
		vector<Point>().swap(v);
	}
	return 0;
}