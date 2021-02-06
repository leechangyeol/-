#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int t, n, k, w;
const int MAX = 1001;
int building[MAX];
int times[MAX];
vector<int> edge[MAX];
int has_edge[MAX];
int ans;
void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (has_edge[i] == 0) {
			q.push(i);
			building[i] = times[i];
		}
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (auto next : edge[here]) {
			building[next] = max(building[next], building[here] + times[next]);
			if (--has_edge[next] == 0)q.push(next);
		}
	}
}
int main(void) {
	cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n >> k;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> times[i];
			edge[i].clear();
			has_edge[i] = 0;
			building[i] = 0;
		}
		int a, b;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
			has_edge[b]++;
		}
		cin >> w;
		bfs();
		cout << building[w] << "\n";
	}
}
