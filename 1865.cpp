#include <iostream>
#include <vector>
using namespace std;

#define MAX 501
#define INF 9999999999

vector<pair<int,pair<int, int>>> vec;
long long dis[MAX];

bool solution() {
	int n, m, w;
	cin >> n >> m >> w;

	dis[1] = 0;

	for (int i = 2; i <= n; i++) {
		dis[i] = INF;
	}

	int s, e, t;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> t;
		vec.push_back({ s,{e,t} });
		vec.push_back({ e,{s,t} });
	}


	for (int i = 0; i < w; i++) {
		cin >> s >> e >> t;
		vec.push_back({ s,{e, -t} });
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < vec.size(); j++) {
			s = vec[j].first;
			e = vec[j].second.first;
			t = vec[j].second.second;

			if (dis[e] > dis[s] + t)dis[e] = dis[s] + t;
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		s = vec[i].first;
		e = vec[i].second.first;
		t = vec[i].second.second;

		if (dis[s] == INF)continue;
		if (dis[e] > dis[s] + t)return true;
	}
	return false;
}
int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		vec.clear();
		if (solution())cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
