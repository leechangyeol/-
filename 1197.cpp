#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int v, e;
int parent[MAX];
int nodeSize[MAX];

int findP(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = findP(parent[x]);
}

int nodeUnion(int a, int b) { //return 0 fail, return 1 success
	int node1 = findP(a);
	int node2 = findP(b);

	if (node1 == node2)return 0;
	
	if (node1 < node2) {
		int temp = node1; node1 = node2; node2 = temp;
	}
	parent[node2] = node1;
	nodeSize[node1] += nodeSize[node2];
	nodeSize[node2] = 0;
	return 1;
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> v >> e;

	vector < pair<int, pair<int, int>>> edge;
	
	for (int i = 1; i <= v; i++) { 
		parent[i] = i; 
		nodeSize[i] = 1;
	}

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(edge.begin(), edge.end());
	long long ans = 0;
	for (int i = 0; i < e; i++) {
		if (nodeUnion(edge[i].second.first, edge[i].second.second) == 1) {
			ans += edge[i].first;
		}
	}
	cout << ans;
}
