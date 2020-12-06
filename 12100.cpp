#include <iostream>
#include <vector>
#include <cstring>
#define MAX 20

using namespace std;

int originMap[MAX][MAX];
int map[MAX][MAX];
int n;
int order[5];
int totalMax = 0;
int move(int dir);
void dfs(int idx);

void dfs(int idx) {
	if (idx == 5) {
		for (int i = 0; i < n; i++) {
			memcpy(map[i], originMap[i], sizeof(int)*n);
		}

		for (int i = 0; i < 5; i++) {
			int temp = move(order[i]);
			if (totalMax < temp) totalMax = temp;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		order[idx] = i;
		dfs(idx + 1);
	}
}

int move(int dir) { //dir  0 왼, 1 오, 2위, 3아래
	if (dir == 0) {
		for (int i = 0; i < n; i++) {
			vector<int> temp;
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0)temp.push_back(map[i][j]);
			}
			int size = temp.size();
			for (int j = 0; j < size; j++) {
				if (j < size - 1 && temp[j] == temp[j + 1] ) {
					temp[j] = temp[j] * 2;
					temp.erase(temp.begin() + j + 1);
					size--;
				}
			}
			for (int j = 0; j < temp.size(); j++) {
				map[i][j] = temp[j];
			}
			for (int j = temp.size(); j < n; j++) {
				map[i][j] = 0;
			}
			
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < n; i++) {
			vector<int> temp;
			
			for (int j = n-1; j >= 0; j--) {
				if (map[i][j] != 0)temp.push_back(map[i][j]);
			}

			int size = temp.size();
			for (int j = 0; j < size; j++) {
				if (j < size - 1 && temp[j] == temp[j + 1]) {
					temp[j] = temp[j] * 2;
					temp.erase(temp.begin() + j + 1);
					size--;
				}
			}

			int t = n - temp.size();
			for (int j = n-1; j >= t; j--) {
				map[i][j] = temp[n - 1 - j];
			}
			for (int j = n - 1 - temp.size(); j >= 0; j--) {
				map[i][j] = 0;
			}
		}

	}
	else if (dir == 2) {
		for (int i = 0; i < n; i++) {
			vector<int> temp;

			for (int j = n - 1; j >= 0; j--) {
				if (map[j][i] != 0)temp.push_back(map[j][i]);
			}
			int size = temp.size();
			for (int j = 0; j < size; j++) {
				if (j < size - 1 && temp[j] == temp[j + 1]) {
					temp[j] = temp[j] * 2;
					temp.erase(temp.begin() + j + 1);
					size--;
				}
			}

			int t = n - temp.size();
			for (int j = n - 1; j >= t; j--) {
				map[j][i] = temp[n - 1 - j];
			}
			for (int j = n - 1 - temp.size(); j >= 0; j--) {
				map[j][i] = 0;
			}
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < n; i++) {
			vector<int> temp;

			for (int j = 0; j < n; j++) {
				if (map[j][i] != 0)temp.push_back(map[j][i]);
			}
			int size = temp.size();
			for (int j = 0; j < size; j++) {
				if (j < size - 1 && temp[j] == temp[j + 1]) {
					temp[j] = temp[j] * 2;
					temp.erase(temp.begin() + j + 1);
					size--;
				}
			}

			for (int j = 0; j < temp.size(); j++) {
				map[j][i] = temp[j];
			}
			for (int j = temp.size(); j < n; j++) {
				map[j][i] = 0;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (max < map[i][j])max = map[i][j];
		}
	}
	return max;
}
int main(void) {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> originMap[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
		order[i] = 0;


	for (int i = 0; i < n; i++) {
		memcpy(map[i], originMap[i], sizeof(int)*n);
	}

	dfs(0);

	cout << totalMax;
}
