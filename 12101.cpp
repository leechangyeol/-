#include <iostream>
#include <vector>
using namespace std;
const int MAX = 11;
int cnt, n, k;
vector<vector<int>> total_list;
void dfs(int num, vector<int> list) {
	int ret = 0;
	if (num == n) {
		total_list.push_back(list);
		return;
	}
	if (num > n)return;
	for (int i = 1; i < 4; i++) {
		vector<int> next = list;
		next.push_back(i);
		dfs(num + i, next);
	}
}
int main(void) {
	cin >> n >> k;
	dfs(0, {});
	if (total_list.size() < k - 1) {
		cout << -1;
		return 0;
	}
	cout << total_list[k - 1][0];
	for (int i = 1; i < total_list[k - 1].size(); i++)
		cout << "+" << total_list[k - 1][i];
}
