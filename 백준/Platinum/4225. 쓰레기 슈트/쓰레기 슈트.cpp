#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Point
{
public:
	int x;
	int y;
	static Point pivot;

	static int ccw(const Point& pt1, const Point& pt2, const Point& pt3)
	{
		ll temp = pt1.x * pt2.y + pt2.x * pt3.y + pt3.x * pt1.y;
		temp -= pt1.y * pt2.x + pt2.y * pt3.x + pt3.y * pt1.x;
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

	static ll dist(const Point& pt1, const Point& pt2)
	{
		return (ll)(pt1.x - pt2.x) * (pt1.x - pt2.x) + (pt1.y - pt2.y) * (pt1.y - pt2.y);
	}

	static long double linedist(const Point& pt1, const Point& pt2, const Point& pt3)
	{
		int p1 = pt2.y - pt1.y;
		int p2 = pt1.x - pt2.x;
		int p3 = pt2.x * pt1.y - pt1.x * pt2.y;
		return abs(p1 * pt3.x + p2 * pt3.y + p3) / sqrt(p1 * p1 + p2 * p2);
	}

	static bool compare(const Point& pt1, const Point& pt2)
	{
		int order = ccw(pivot, pt1, pt2);
		if (!order)
		{
			return dist(pivot, pt1) < dist(pivot, pt2);
		}
		return order > 0;
	}

	static void Set(const vector<Point>& v)
	{
		pivot = *min_element(v.begin(), v.end(), [](const Point& a, const Point& b)
			{
				return (a.y == b.y) ? a.x < b.x : a.y < b.y;
			});
	}
};

Point Point::pivot;
int num = 0, cnt = 1;
vector<Point>v;

void convex_hull()
{
	long double result = LLONG_MAX;
	vector<Point>s;
	Point::Set(v);
	sort(v.begin(), v.end(), Point::compare);
	int size = v.size();
	for (int i = 0; i < size; ++i)
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
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		int z = (i + 1) % len;
		long double temp = 0;
		for (int j = 0; j < len; ++j)
		{
			temp = max(temp, Point::linedist(s[i], s[z], s[j]));
		}
		result = min(result, temp);
	}
	cout << "Case " << cnt << ": ";
	cout << fixed << setprecision(2) << ceil(result * 100) / 100 << "\n";
	cnt++;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1)
	{
		cin >> num;
		if (!num)
		{
			exit(0);
		}
		v.resize(num);
		for (int i = 0; i < num; ++i)
		{
			cin >> v[i].x >> v[i].y;
		}
		convex_hull();
		vector<Point>().swap(v);
	}
}