#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
#define INT_MAX 987654321

using namespace std;

int n, d, s;
vector<pair<int, int>> adj[MAX];
int dist[MAX];
void dijkstra(void) {
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> qu;

	dist[s] = 0;

	qu.push(make_pair(0, s));

	while (!qu.empty()) {
		int here_dist = qu.top().first;
		int here = qu.top().second;
		qu.pop();

		if (dist[here] < here_dist) continue;

		for (auto there_ind : adj[here]) {
			int there_dist = there_ind.second;
			int there = there_ind.first;
			if (dist[there] > there_dist + here_dist) {
				qu.push(make_pair(there_dist + here_dist, there));
				dist[there] = there_dist + here_dist;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int test;
	int ans;
	int cnt;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n >> d >> s;

		ans = 0;
		cnt = 0;

		for (int i = 1; i <= n; i++) { 
			adj[i].clear();
			dist[i] = INT_MAX;
		}

		for (int i = 0; i < d; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[b].push_back(make_pair(a, c));
		}

		dijkstra();

		for (int i = 1; i <= n; i++) {
			if (dist[i] != INT_MAX) {
				ans = max(dist[i], ans);
				cnt++;
			}
		}

		cout << cnt << " " << ans << "\n";
	}
}
