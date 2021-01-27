#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, m, w;
const int MAX = 501;
const int INF = 987654321;
vector<pair<int, int>> edge[MAX];
int flag;
int dist[MAX][MAX];
void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
		for (auto next : edge[i])
			dist[i][next.second] = min(dist[i][next.second], next.first);
	}
	for (int start = 1; start <= n; start++) {
		for (int end = 1; end <= n; end++) {
			for (int mid = 1; mid <= n; mid++) {
				if (dist[start][mid] == INF || dist[mid][start] == INF)continue;
				dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end]);
			}
		}
	}
}
int main(void) { 
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> t; 
	for (int test = 0; test < t; test++) {
		cin >> n >> m >> w;
		flag = 0;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back({ c,b });
			edge[b].push_back({ c,a });
		}
		for (int i = 0; i < w; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edge[a].push_back({ -c,b });
		}
		floyd();
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++)
				if (dist[i][j] + dist[j][i] < 0)
					flag = 1;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		for (int i = 1; i <= n; i++)edge[i].clear();
		memset(dist, 0, sizeof(dist));
	}
}
