#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50001;
int n;
int p[MAX];
int depth[MAX];
vector<int> link[MAX];
void dfs(int node,int level) {
	for (auto next : link[node]) {
		if (!p[next]) {
			p[next] = node;
			depth[next] = level;
			dfs(next, level + 1);
		}
	}
}
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}
	p[1] = 1;
	dfs(1, 1);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (depth[a] > depth[b])swap(a, b);
		while (depth[a] != depth[b]) b = p[b];
		while (a != b) a = p[a], b = p[b];
		cout << a << "\n";
	}
	
}
