#include <iostream>
#include <algorithm>
using namespace std;
int r, c;
char map[20][20];
bool visited[20][20];
bool ch[26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans;
void dfs(int x, int y,int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < c && ny >= 0 && ny < r && !visited[ny][nx] && !ch[map[ny][nx]]) {
			visited[ny][nx] = 1;
			ch[map[ny][nx]] = 1;
			dfs(nx, ny, cnt + 1);
			visited[ny][nx] = 0;
			ch[map[ny][nx]] = 0;
		}
	}
}
int main(void) {
	cin >> r >> c;
	char temp;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> temp;
			map[i][j] = (int)temp - 65;
		}
	}
	
	dfs(0, 0, 0);
	cout << ans;
}
