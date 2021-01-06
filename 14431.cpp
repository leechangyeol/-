#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define MAX 8500
int prime[MAX];
using namespace std;

vector<pair<int, int>> node;
vector<vector<pair<int, int>>> edge; // A , B, dist
vector<int> mindist;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int n;
int main(void) {

	for (int i = 2; i < MAX; i++) {
		if (prime[i] == 0) {
			int a = i;
			prime[i] = 1;
			while (1) {
				a += i;
				if (a >= MAX)break;
				prime[a] = 2;
			}
		}
	}

	int x1, x2, y1, y2;

	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n;
	n += 2;

	node = vector<pair<int, int>>(n + 1);
	edge = vector<vector<pair<int, int>>>(n + 1);
	mindist = vector<int>(n + 1, MAX);
	node[1].first = x1; node[1].second = y1; node[2].first = x2; node[2].second = y2;

	int dist = sqrt(pow(node[1].first - node[2].first, 2) + pow(node[1].second - node[2].second, 2));
	if (prime[dist] == 1) {
		edge[1].push_back({ dist,2 }); edge[2].push_back({ dist,1 });
	}

	for (int i = 3; i < n + 1; i++) {
		cin >> node[i].first >> node[i].second;
		for (int j = 1; j < i; j++) {
			dist = sqrt(pow(node[j].first - node[i].first,2) + pow(node[j].second - node[i].second,2));
			if (prime[dist] == 1) { edge[i].push_back({ dist,j }); edge[j].push_back({ dist,i }); }
		}
	}
	
	mindist[1] = 0;

	pq.push({ 0,1 });
	while (!pq.empty()) {
		int dist = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (mindist[x] < dist)continue;

		for (auto next : edge[x]) {
			if (mindist[x] + next.first < mindist[next.second]) {
				mindist[next.second] = mindist[x] + next.first;
				pq.push({ next.first,next.second });
			}
		}
	}
	if (mindist[2] == MAX)mindist[2] = -1;
	cout << mindist[2];
}
