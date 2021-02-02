#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
const int MAX = 101;
vector<pair<int, int>> items;
int value[MAX][100001];
int main(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		items.push_back({ a,b });
	}
	for (int i = 0; i <= k; i++) {
		if (i >= items[0].first)
			value[0][i] = items[0].second;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j < items[i].first) value[i][j] = value[i - 1][j];
			else value[i][j] = max(value[i - 1][j], value[i - 1][j - items[i].first] + items[i].second);
		}
	}
	cout << value[n - 1][k];
}
