#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100001;
int list[MAX];
bool visited[MAX];
bool done[MAX];
int n;
int ans;
void dfs(int node) {
	visited[node] = true;

	if (!visited[list[node]])
		dfs(list[node]);
	else if (!done[list[node]]) {
		for (int i = list[node]; i != node; i = list[i])
			ans++;
		ans++;
	}

	done[node] = true;
}
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n;
		ans = 0;

		for (int i = 1; i <= n; i++) {
			cin >> list[i];
		}
		for (int i = 1;i<=n;i++)
			if (!visited[i])  
				dfs(i);

		cout << n - ans << "\n";
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
	}
}
