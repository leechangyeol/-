#include <iostream>
#include <vector>
#include <functional>
#include <queue>

#define MAX 32001

using namespace std;

int n, m;
vector<int> edge[MAX];
int edgeN[MAX];
priority_queue<int,vector<int>,greater<int>> result;

void topo(void) {

	for (int i = 1; i <= n; i++) {
		if (edgeN[i] == 0) {
			result.push(i);
		}
	}

	while (!result.empty()) {
		int x = result.top();
		result.pop();
		cout << x << " ";
		for (int i = 0; i < edge[x].size(); i++) {
			if (--edgeN[edge[x][i]] == 0) {
				result.push(edge[x][i]);
			}
		}
		
	}
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		edgeN[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edgeN[b]++;
	}
	topo();

}
