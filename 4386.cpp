#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 1000

using namespace std;
struct edge {
	double d;
	int a, b;
};
vector<edge> edges;
pair<double, double> stars[MAX];
int parent[MAX];

int getParent(int x)
{
	if (x == parent[x])return x;
	else return parent[x] = getParent(parent[x]);
}

bool find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return (a == b);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int n;
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;

		stars[i] = { x,y };
	
		parent[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double d = (stars[i].first - stars[j].first) * (stars[i].first - stars[j].first)
				+ (stars[i].second - stars[j].second) * (stars[i].second - stars[j].second);
			d = sqrt(d);
			edges.push_back({ d, i, j });
		}
	}

	sort(edges.begin(), edges.end(), [](edge& e1, edge& e2) -> bool {return e1.d < e2.d; });

	double ans = 0;
	int cnt = 0;

	for (int i = 0; i < edges.size(); i++)
	{
		if (!find(edges[i].a, edges[i].b))
		{
			ans += edges[i].d;
			unionParent(edges[i].a, edges[i].b);
			if (++cnt == n)break;
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << ans;
}
