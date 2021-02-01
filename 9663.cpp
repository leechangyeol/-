#include <iostream>
using namespace std;
int n;
const int MAX = 15;
int map[MAX];
int ans;
bool check(int level,int x) {
	for (int i = 0; i < level; i++) {
		if (map[i] == x || abs(i-level) == abs(x-map[i]))return false;
	}
	return true;
}
void dfs(int level) {
	if (n == level) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check(level,i)) {
			map[level] = i;
			dfs(level + 1);
		}
	}
}
int main(void) {
	cin >> n;
	dfs(0);
	cout << ans;
}
