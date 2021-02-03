#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
const int MAX = 1025;
int map[MAX][MAX];
int acc[MAX][MAX];
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			acc[i + 1][j + 1] = acc[i][j + 1] + acc[i + 1][j] + map[i][j] - acc[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		cout << acc[y2][x2] - acc[y1 - 1][x2] - acc[y2][x1 - 1] + acc[y1-1][x1-1] << "\n";
	}

}
