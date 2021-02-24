#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 101;
int map[MAX][MAX];
bool visited[MAX][MAX];
int h, w;
bool key[26];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> door[26];
int ans;
queue<pair<int, int>> q;
void checking(int y, int x) {
	if (map[y][x] == '.') { q.push({ y,x }); visited[y][x] = 1; }
	else if ('A' <= map[y][x] && 'Z' >= map[y][x]) {
		if (key[map[y][x] - 'A']) {
			q.push({ y,x });
			visited[y][x] = 1;
		}
		else {
			door[map[y][x] - 'A'].push_back({ y,x });
		}
	}
	else if ('a' <= map[y][x] && 'z' >= map[y][x]) {
		key[map[y][x] - 'a'] = true;
		q.push({ y,x });
		visited[y][x] = 1;
		for (auto next : door[map[y][x] - 'a'])
			if (!visited[next.first][next.second]) {
				q.push({ next.first,next.second });
				visited[next.first][next.second];
			}
	}
	else if (map[y][x] == '$') {
		q.push({ y,x });
		ans++;
		visited[y][x] = 1;
	}
}
int main(void) {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		ans = 0;
		cin >> h >> w;
		string temp;
		for (int i = 0; i < h; i++) {
			cin >> temp;
			for (int j = 0; j < w; j++) {
				map[i][j] = temp[j];
			}
		}
		cin >> temp;
		if (temp != "0") {
			for (auto ch : temp){
				key[ch - 'a'] = true;
			}
		}
		for (int i = 0; i < w; i++) {
			checking(0, i);
			checking(h - 1, i);
		}
		for (int i = 1; i < h-1; i++) {
			checking(i, 0);
			checking(i, w - 1);
		}

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			visited[y][x] = 1;
			for (int i = 0; i < 4; i++) {
				int ny = dy[i] + y;
				int nx = dx[i] + x;
				if (ny < h && ny >= 0 && nx < w && nx >= 0 && !visited[ny][nx] && map[ny][nx] != '*') {
					checking(ny, nx);
				}
			}
		}
		cout << ans << "\n";
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		memset(key, 0, sizeof(key));
		for (int i = 0; i < 26; i++)
			door[i].clear();
	}
}
