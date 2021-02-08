#include <iostream>
using namespace std;
const int MAX = 10;
bool row[MAX][MAX];
bool colum[MAX][MAX];
bool site[MAX][MAX];
int map[MAX][MAX];
int ans_x, ans_y;
int dfs(int x, int y) {
	if (x == ans_x && y == ans_y) {
		for (int k = 1; k < MAX; k++) {
			if (!colum[y][k] && !row[x][k] && !site[y / 3 * 3 + x / 3][k]) {
				map[y][x] = k;
				return 1;
			}
		}
	}
	else {
		if (map[y][x] != 0) {
			if (x + 1 > 8) { if (dfs(0, y + 1))return 1; }
			else { if (dfs(x + 1, y)) return 1; }
		}
		else {
			for (int k = 1; k < MAX; k++)
				if (!colum[y][k] && !row[x][k] && !site[y / 3 * 3 + x / 3][k]) {
					map[y][x] = k;
					colum[y][k] = row[x][k] = site[y / 3 * 3 + x / 3][k] = true;
					if (x + 1 > 8) { if (dfs(0, y + 1))return 1; }
					else { if(dfs(x + 1, y)) return 1; }
					map[y][x] = 0;
					colum[y][k] = row[x][k] = site[y / 3 * 3 + x / 3][k] = false;
				}
			}
		}
	return 0;
}
int main(void) {
	ans_x = -1;
	for (int i = 0; i < MAX - 1; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < MAX - 1; j++) {
			map[i][j] = temp[j] - '0';
			colum[i][map[i][j]] = true;
			row[j][map[i][j]] = true;
			site[i / 3 * 3 + j / 3][map[i][j]] = true;
			if (map[i][j] == 0) {
				ans_x = j; ans_y = i;
			}
		}
	}
	
	dfs(0, 0);
	
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++)
			cout << map[i][j];
		cout << "\n";
	}
	
}
