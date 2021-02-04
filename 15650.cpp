#include <iostream>
using namespace std;
int n, m;
const int MAX = 8;
int map[MAX];
void dfs(int cnt, int idx) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << map[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = idx; i < n; i++) {
			map[cnt] = i + 1;
			dfs(cnt + 1, i + 1);
		}
	}
}
int main(void) {
	cin >> n >> m;
	dfs(0, 0);
}
