#include <iostream>
#include <vector>
using namespace std;
int n;
const int MAX = 100001;
vector<int> edge[MAX];
int ans[MAX];
bool visited[MAX];
void dfs(int node) {
	for (auto next : edge[node]) {
		if (!visited[next]) {
			visited[next] = 1;
			ans[next] = node;
			dfs(next);
		}
	}
}
int main(void) {
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	visited[1] = 1;
	dfs(1);
	for (int i = 2; i <= n; i++) { 
		cout << ans[i] << "\n";
	}
}
