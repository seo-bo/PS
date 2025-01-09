#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Point
{
public:
	int x, y;
	static pair<Point, int> pivot;

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
		return -1;
	}

	static ll dist(const Point& p1, const Point& p2)
	{
		return (ll)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}

	static bool compare(const pair<Point, int>& p1, const pair<Point, int>& p2)
	{
		int order = ccw(pivot.first, p1.first, p2.first);
		if (!order)
		{
			return dist(pivot.first, p1.first) < dist(pivot.first, p2.first);
		}
		return order > 0;
	}

	static void Set(const vector<pair<Point, int>>& pt)
	{
		pivot = *min_element(pt.begin(), pt.end(), [](const pair<Point, int>& a, const pair<Point, int>& b)
			{
				return (a.first.y == b.first.y) ? a.first.x < b.first.x : a.first.y < b.first.y;
			});
	}
};

pair<Point, int> Point::pivot;
int num = 0;
vector<pair<Point, int>>v;

void convex_hull()
{
	num--;
	Point::Set(v);
	sort(v.begin(), v.end(), Point::compare);
	while (!Point::ccw(Point::pivot.first, v[num -1].first, v[num].first))
	{
		num--;
	}
	reverse(v.begin() + num, v.end());
	for (auto& i : v)
	{
		cout << i.second << " ";
	}
	cout << "\n";
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
			cin >> v[i].first.x >> v[i].first.y;
			v[i].second = i;
		}
		convex_hull();
		vector<pair<Point, int>>().swap(v);
		pair<Point, int> ().swap(Point::pivot);
	}
	return 0;
}