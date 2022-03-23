#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 555

using namespace std;
struct edge {
	double d;
	int a, b;
};

vector<edge> edges;
vector<double> connectedEdges;
pair<double, double> outposts[MAX];

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

int n, s, t;
int main(void)
{
	cin >> t;

	while (t--)
	{
		cin >> s >> n;
	

		for (int i = 0; i < n; i++)
		{
			double x, y;
			cin >> x >> y;

			outposts[i] = { x,y };

			parent[i] = i;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				double d = (outposts[i].first - outposts[j].first) * (outposts[i].first - outposts[j].first)
					+ (outposts[i].second - outposts[j].second) * (outposts[i].second - outposts[j].second);
				d = sqrt(d);
				edges.push_back({ d, i, j });
			}
		}

		sort(edges.begin(), edges.end(), [](edge& e1, edge& e2) -> bool {return e1.d < e2.d; });

		double ans = 0.;
		int cnt = n - s;

		int i = 0;
		while (1)
		{
			if (!find(edges[i].a, edges[i].b))
			{
				ans = edges[i].d;
				unionParent(edges[i].a, edges[i].b);
				if (--cnt == 0)break;
			}
			i++;
		}
			


		cout << fixed;
		cout.precision(2);

		cout << ans << "\n";
	}
	
}
