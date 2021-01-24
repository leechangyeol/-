#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 20001;
vector<pair<int,int>> edge[MAX];
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[MAX];
int V, E, start;

void dijkstra(int startNode) {
	int node, value;
	dist[startNode] = 0;
	pq.push({ 0, startNode });
	while (!pq.empty()) {
		node = pq.top().second;
		value = pq.top().first;
		pq.pop();
		for (auto next : edge[node]) {
			if (dist[next.second] == -1) {
				dist[next.second] = next.first + value;
				pq.push({ next.first + value, next.second });
			}
			else if(dist[next.second] > value + next.first){
				dist[next.second] =  value + next.first;
				pq.push({ next.first + value, next.second });
			}
		}
	}
}
int main(void) {

	cin >> V >> E;
	cin >> start;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edge[u].push_back({ w,v });
	}
	memset(dist, -1, sizeof(dist));
	dijkstra(start);
	for (int i = 1;i<=V;i++)
	{
		if (dist[i] == -1)cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}
