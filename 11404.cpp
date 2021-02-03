#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
const int MAX = 101;
const int INF = 98765432;
int map[MAX][MAX];
vector<pair<int,int>> edge[MAX];
int main(void) {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)map[i][j] = 0;
			else map[i][j] = INF;
		}
		for (auto next : edge[i])
			map[i][next.first] = min(map[i][next.first], next.second);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if(map[j][i] != INF && map[i][k] != INF)
					map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (map[i][j] == INF)cout << 0 << " ";
			else cout << map[i][j] << " ";
		cout << "\n";
	}
}
