#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1001;
int n, m;
int nodeCount[MAX];
vector<int> edge[MAX];
int main(void) {
	cin >> n >> m;
	int count, a, b;
	for (int i = 0; i < m; i++) {
		cin >> count;
		cin >> a;
		for (int j = 1; j < count; j++) {
			cin >> b;
			edge[a].push_back(b);
			nodeCount[b]++;
			a = b;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (nodeCount[i] == 0) { 
			q.push(i);
			nodeCount[i]--;
		}
	}

	vector<int> ans;
	int node;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		ans.push_back(node);
		for (auto next : edge[node]) {
			if (--nodeCount[next] == 0) {
				q.push(next);
				nodeCount[next]--;
			}
		}
	}

	if (ans.size() != n) { cout << 0; return 0; }
	else {
		for (auto ans_next : ans)
			cout << ans_next << "\n";
	}
}
