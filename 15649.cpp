#include <iostream>
using namespace std;
int n, m;
const int MAX = 8;
int map[MAX];
bool visited[MAX];
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << map[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visited[i+1]) {
				visited[i + 1] = 1;
				map[cnt] = i + 1;
				dfs(cnt + 1);
				visited[i + 1] = 0;
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	dfs(0);
}
