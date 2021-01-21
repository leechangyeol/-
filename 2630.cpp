#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
const int MAX = 128;
int map[MAX][MAX];
int ans[2];
int check(int x, int y, int size) {
	int color = map[y][x];
	int size_y = y + size;
	int size_x = x + size;
	for (int i = y; i < size_y; i++) {
		for (int j = x; j < size_x; j++) {
			if (color != map[i][j])return -1;
		}
	}
	for (int i = y; i < size_y; i++) {
		for (int j = x; j < size_x; j++) {
			map[i][j] = 2;
		}
	}
	
	ans[color]++;
	return 0;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int before = n;
	while (n) {
		for (int i = 0; i < before; i += n) {
			for (int j = 0; j < before; j += n) {
				if (map[i][j] != 2)
					check(j, i, n);
			}
		}
		n /= 2;
	}
	cout << ans[0] << "\n" << ans[1];
}
