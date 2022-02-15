#include <iostream>
#include <vector>
using namespace std;

#define MAX 501
#define INF 9999999999

vector<pair<int,pair<int, int>>> vec;
long long dis[MAX];

int main(void)
{
	int n, m;
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		vec.push_back({ a,{b,c} });
	}

	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}

	dis[1] = 0;

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < vec.size(); j++) {
			a = vec[j].first;
			b = vec[j].second.first;
			c = vec[j].second.second;

			if (dis[a] == INF) continue;
			if (dis[b] > dis[a] + c)dis[b] = dis[a] + c;
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		a = vec[i].first;
		b = vec[i].second.first;
		c = vec[i].second.second;

		if (dis[a] == INF) continue;
		if (dis[b] > dis[a] + c) {
			cout << "-1";
			return 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (dis[i] == INF)cout << "-1\n";
		else cout << dis[i] << "\n";
	}
	return 0;
}
