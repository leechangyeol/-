#include <iostream>
#include <queue>
using namespace std;
int m, n;
const int MAX = 1001;
int map[MAX][MAX];
queue<pair<pair<int, int>,int>> st;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans;
int check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0)return 0;
	return 1;
}
void bfs() {
	int x, y,day;
	while (!st.empty()) {
		y = st.front().first.first;
		x = st.front().first.second;
		day = st.front().second;
		
		st.pop();
		ans = max(ans,day);
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < m && nx >= 0 && ny >= 0 && ny < n && map[ny][nx] == 0) {
				map[ny][nx] = 1;
				st.push({ {ny,nx},day + 1 });
				
			}
		}
	}
}
int main(void) {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)st.push({{ i,j },0});
		}
	}

	bfs();
	if (check())
		cout << ans;
	else cout << -1;
	return 0;
}
