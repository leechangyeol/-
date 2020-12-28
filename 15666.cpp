#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int pos[9];
int n, m;
vector<int> item;

void dfs(int cnt,int start) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << item[pos[i]] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = start; i <= n; i++) {
		pos[cnt] = i;
		dfs(cnt + 1,i);
	}
}
int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		int b = 0;
		for (auto com : item) {
			if (com == a) b = 1;
		}
		if (b == 0)item.push_back(a);
	}
	n = item.size()-1;
	sort(item.begin(), item.end());
	dfs(0,0);
}
