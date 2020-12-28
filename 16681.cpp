#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF 100000000000000000
using namespace std;

int N, M, D, E;
vector<long long> height, dist1, dist2;
vector<pair<int,long long>> edge[MAX];

int main(void) {
	cin >> N >> M >> D >> E;

	dist1 = dist2 = height = vector<long long>(N + 1, -1);
	for (int i = 1; i <= N; i++) {
		cin >> height[i];
	}
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
	}

	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

	int here = 1;
	long long dist = 0;

	dist1[here] = 0;
	pq.push(make_pair(dist, here));
	while (!pq.empty()) {
		dist = pq.top().first;
		here = pq.top().second;
		pq.pop();
		if (dist1[here] < dist)continue;

		for (auto next : edge[here]) {
			if (height[next.first] <= height[here])continue;
			if (dist1[next.first] == -1) {
				dist1[next.first] = dist + next.second;
				pq.push({ dist + next.second, next.first });
			}
			else if (dist1[next.first] > dist + next.second) {
				dist1[next.first] = dist + next.second;
				pq.push({ dist + next.second, next.first });
			}
		}
	}

	here = N;
	dist = 0;

	dist2[here] = 0;
	pq.push(make_pair(dist, here));
	while (!pq.empty()) {
		dist = pq.top().first;
		here = pq.top().second;
		pq.pop();
		if (dist2[here] < dist)continue;

		for (auto next : edge[here]) {
			if (height[next.first] <= height[here])continue;
			if (dist2[next.first] == -1) {
				dist2[next.first] = dist + next.second;
				pq.push({ dist + next.second, next.first });
			}
			else if (dist2[next.first] > dist + next.second) {
				dist2[next.first] = dist + next.second;
				pq.push({ dist + next.second, next.first });
			}
		}
	}
	long long ans = -INF;
	for (int i = 1; i <= N; i++) {
		if (dist1[i] == -1 | dist2[i] == -1)continue;
		if (ans < height[i] * E - (dist1[i] + dist2[i])*D)
			ans = height[i] * E - (dist1[i] + dist2[i])*D;
	}
	if (ans == -INF)cout << "Impossible";
	else cout << ans;

}
