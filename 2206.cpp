#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
const int MAX = 1001;
const int INF = 9876543;
int map[MAX][MAX];
int visited[MAX][MAX];
int ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void bfs() {
	int x, y;
	int jumpflag;
	int num = 1;
	jumpflag = x = y = 0;
	queue<pair<pair<int, int>,pair< int,int>>> q;
	q.push({ {x,y},{jumpflag,num} });
	visited[y][x] = 1;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		jumpflag = q.front().second.first;
		num = q.front().second.second;
		if (x == m - 1 && y == n - 1) { ans = num; return; }
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[ny][nx] != 1) {
				if (map[ny][nx] == 1) {
					if (jumpflag == 0) {
						visited[ny][nx] = 2;
						q.push({ {nx,ny},{1,num + 1} });
					}
					else continue;
				}
				else {
					if (jumpflag == 1 && visited[ny][nx] == 2)continue;
					if (jumpflag == 1)visited[ny][nx] = 2;
					else visited[ny][nx] = 1;
					q.push({ {nx,ny},{jumpflag,num + 1} });
				}
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++)
			map[i][j] = int(temp[j]-'0');
	}
	ans = INF;
	bfs();
	if (ans == INF)cout << -1;
	else cout << ans;
}
