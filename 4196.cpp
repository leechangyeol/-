#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX 100000
using namespace std;

vector<vector<int>> edge;
vector<bool> finish;
vector<int> discover;
vector<vector<int>> SCC;
vector<int> sccidx;
vector<bool> sccfinish;
stack<int> st;
int n, m;
int nodeN;
int sccN;
int min(int a, int b) { if (a >= b)return b; else return a; }

int dfs(int node) {
	
	discover[node] = ++nodeN;
	st.push(node);
	int parent = nodeN;
	for (int i = 0; i < edge[node].size(); i++) {
		if (discover[edge[node][i]] == -1)
			parent = min(parent, dfs(edge[node][i]));
		else if (!finish[edge[node][i]])
			parent = min(parent, discover[edge[node][i]]);
	}

	if (discover[node] == parent && !finish[node]) {
		sccN++;
		while (1) {
			int top = st.top();
			st.pop(); 
			SCC[sccN].push_back(top);
			finish[top] = true;
			sccidx[top] = sccN;
			if (top == node)break;
		}
	}

	return parent;
}
int main(void){
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int time = 0;
	cin >> time;
	for (int t = 0; t < time; t++) {
		cin >> n >> m;

		edge = vector<vector<int>>(n + 1);
		finish = vector<bool>(n + 1, false);
		discover = vector<int>(n + 1, -1);
		SCC = vector<vector<int>>(n + 1);
		sccidx = vector<int>(n + 1);
		nodeN = 0;
		sccN = 0;

		for (int i = 0; i < m; i++) {
			int temp_a, temp_b;
			cin >> temp_a >> temp_b;
			edge[temp_a].push_back(temp_b);
		}

		for (int i = 1; i <= n; i++) {
			dfs(i);
		}
		sccfinish = vector<bool>(sccN + 1, false);
		queue<int> sccbfs;
		int ans = 0;
		for (int i = sccN; i > 0; i--) {
			if (sccfinish[i])continue;
			ans++;
			sccbfs.push(i);
			sccfinish[i] = true;
			while (!sccbfs.empty()) {
				int x = sccbfs.front();
				sccbfs.pop();
				for (auto next : SCC[x]) {
					for (auto nextNode : edge[next]) {
						if (!sccfinish[sccidx[nextNode]]) {
							sccbfs.push(sccidx[nextNode]);
							sccfinish[sccidx[nextNode]] = true;
						}
					}
				}
			}

		}
		cout << ans << "\n";
	}
}
