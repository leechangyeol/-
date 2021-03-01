#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
int list[MAX];
bool finished[MAX];
int n;
int ans;
vector<int> linked;
void dfs(int node) {
	auto it = find(linked.begin(), linked.end(),node);
	if (it != linked.end()) {
		ans += it - linked.begin();
	}
	else {
		finished[node] = 1;
		linked.push_back(node);
		dfs(list[node]);
	}
}
int main(void) {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> list[i];
		}
		for (auto next : list)
			if (!finished[next]) { 
				dfs(next);
				linked.clear();
			}
		cout << ans<<"\n";
	}
}
