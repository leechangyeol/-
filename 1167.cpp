#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 1000001;
int n; 
vector<pair<int, int>> edge[MAX];
bool visit[MAX];
int temp_max;
int leaf;
void dfs(int node, int value) {
	visit[node] = 1;
	for (auto next : edge[node]) {
		if (visit[next.first])continue;
		if (temp_max < value + next.second) {
			leaf = next.first;
			temp_max = value + next.second;
		}
		dfs(next.first, next.second + value);
	}
}
int main(void) {
	cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int node, next, value;
		cin >> node;
		while (1) {
			cin >> next;
			if (next == -1)break;
			cin >> value;
			edge[node].push_back({ next,value });
		}
	}

	int ans_max = 0;
	dfs(1, 0);
	memset(visit, 0, size(visit));
	dfs(leaf, 0);
	cout << temp_max;
}
