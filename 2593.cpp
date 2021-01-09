#include <iostream>
#include <vector>
#include <queue>
#define LAYER_MAX 100000 + 1
#define ELEVATOR_MAX 100 + 1
using namespace std;

int n, m, s, e;
vector<int> layer[LAYER_MAX];
vector<int> group[ELEVATOR_MAX];
vector<int> route;
queue<pair<int,int>> q;
int visitGroup[ELEVATOR_MAX];

int dfs() {
	for (auto s_layer : layer[s]) {
		q.push({ s_layer,1 });
		visitGroup[s_layer] = 1;
	}
	
	while (!q.empty()) {
		int here = q.front().first;
		int dist = q.front().second;

		q.pop();
		
		route[dist] = here;
		
		for (auto next_layer : group[here]) {
			if (next_layer == e)
				return here;
		}
		
		for (int i = 0; i < group[here].size(); i++) {
			for (int j = 0; j < layer[group[here][i]].size(); j++){
				if (visitGroup[layer[group[here][i]][j]] == 0 ) {
					q.push({ layer[group[here][i]][j],dist + 1 });
					visitGroup[layer[group[here][i]][j]] = dist + 1;
				}
			}
		}

	}
	return 0;
}
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	cin >> n >> m;

	for (int i = 1; i <= m; i++){
		int start; int step;
		cin >> start >> step;
		while (start < n + 1) {
			layer[start].push_back(i);
			group[i].push_back(start);
			start += step;
		}
	}

	cin >> s >> e;

	route = vector<int>(m + 2, 0);
	int here;
	
	here = dfs();
	
	if (here == 0) {
		cout << -1; return 0;
	}
	cout << visitGroup[here];
	for (int i = 1; i <= visitGroup[here]; i++)
		cout << "\n" << route[i];
	return 0;
}
