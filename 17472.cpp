#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 11
using namespace std;
int m, n;
int map[MAX][MAX];
int minDis[7][7];
int parent[7];
int nodeSize[7];
int ic;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int, int>> island[7];
vector<pair<int, pair<int, int>>> edge;

void bfs(int x, int y,int ic) {
	map[y][x] = ic;
	island[map[y][x]].push_back({ y,x });
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] == -1) {
			bfs(nx, ny, ic);
		}
	}
}
int findP(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = findP(parent[x]);
}
int unionNode(int a, int b) {
	int node1 = findP(a);
	int node2 = findP(b);

	if (node1 == node2)return 0;

	if (nodeSize[node1] < nodeSize[node2])swap(node1, node2);
	nodeSize[node1] += nodeSize[node2];
	nodeSize[node2] = 0;
	parent[node2] = node1;

	return 1;
}
void bridge(int y, int x) {
	int leftX,rightX;
	leftX = rightX = x;
	int leftY, rightY;
	leftY = rightY = y;
	while (1) {
		leftX--;
		if (leftX < 0)break;
		if (map[y][leftX] == map[y][x])break;
		if (map[y][leftX] != 0) {
			if (minDis[map[y][x]][map[y][leftX]] == -1) {
				if (x - leftX < 3) break; 
				minDis[map[y][x]][map[y][leftX]] = x - leftX - 1;
				break;
			}
			else if (minDis[map[y][x]][map[y][leftX]] > x - leftX-1) {
				if (x - leftX < 3)break;
				minDis[map[y][x]][map[y][leftX]] = x - leftX - 1;
				break;
			}
			break;
		}
	}
	while (1) {
		rightX++;
		if (rightX >= m)break;
		if (map[y][rightX] == map[y][x])break;
		if (map[y][rightX] != 0) {
			if (minDis[map[y][x]][map[y][rightX]] == -1) {
				if (rightX - x < 3)break; 
				minDis[map[y][x]][map[y][rightX]] = rightX - x - 1;
				break;

			}
			else if (minDis[map[y][x]][map[y][rightX]] > rightX - x -1) {
				if (rightX - x < 3)break; 
				minDis[map[y][x]][map[y][rightX]] = rightX - x - 1;
				break;
			}
			break;
		}
	}
	while (1) {
		leftY--;
		if (leftY < 0)break;
		if (map[y][x] == map[leftY][x])break;
		if (map[leftY][x] != 0) {
			if (minDis[map[y][x]][map[leftY][x]] == -1) {
				if (y - leftY < 3)break; 
				minDis[map[y][x]][map[leftY][x]] = y - leftY - 1; break;
			}
			else if (minDis[map[y][x]][map[leftY][x]] > y - leftY -1) {
				if (y - leftY < 3)break; 
				minDis[map[y][x]][map[leftY][x]] = y - leftY - 1; 
				break;
			}
			break;
		}
	}
	while (1) {
		rightY++;
		if (rightY >= n)break;
		if (map[rightY][x] == map[y][x])break;
		if (map[rightY][x] != 0) {
			if (minDis[map[y][x]][map[rightY][x]] == -1) {
				if (rightY - y < 3)break; 
				minDis[map[y][x]][map[rightY][x]] = rightY - y - 1; 
				break;
			}
			else if (minDis[map[y][x]][map[rightY][x]] > rightY - y -1 ){
				if (rightY - y < 3)break; 
				minDis[map[y][x]][map[rightY][x]] = rightY - y - 1; 
				break;
			}
			break;
		}
	}
}
int main(void) {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	int a;
	ic = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a == 1) {
				map[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1)bfs(j, i, ++ic);
		}
	}
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j < 7; j++) {
			minDis[i][j] = -1;
		}
		parent[i] = i;
		nodeSize[i] = 1;
	}

	for (int i = 1; i <= 6; i++) {
		for (auto pos : island[i]) {
			bridge(pos.first, pos.second);
		}
	}

	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (minDis[i][j] != -1)edge.push_back({ minDis[i][j], {i, j} });
		}
	}
	int ans = 0;
	sort(edge.begin(), edge.end());
	for (auto next : edge) {
		if (unionNode(next.second.first, next.second.second) == 1) {
			ans += next.first;
		}
	}
	int unionCheck = parent[1];
	for (int i = 1; i <= ic;i++) {
		if (findP(i) != unionCheck) {
			cout << -1; return 0;
		}
	}

	cout << ans;
	return 0;
}
