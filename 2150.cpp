#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;
vector<int> edge[MAX];
stack<int> st;
vector<vector<int>> SCC;
int nodeParent[MAX];
int nodeOrder;
int finish[MAX];
int v, e;
int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}
int dfs(int node) {
	st.push(node);
	nodeParent[node] = ++nodeOrder;
	int parent = nodeParent[node];
	for (int i = 0; i < edge[node].size(); i++) {
		int nextNode = edge[node][i];
		if (finish[nextNode] == 0 && nodeParent[nextNode] == 0) {
			parent = min(parent, dfs(nextNode));
		}
		else if(finish[nextNode] == 0)
			parent = min(parent, nodeParent[nextNode]);
	}

	if (nodeParent[node] == parent) {
		vector<int> tempSCC;
		while (1) {
			int top = st.top();
			st.pop();
			tempSCC.push_back(top);
			finish[top] = 1;
			if (top == node)break;
		}
		sort(tempSCC.begin(),tempSCC.end());
		tempSCC.push_back(-1);
		SCC.push_back(tempSCC);
	}

	return parent;
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	nodeOrder = 0;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= v; i++)
		finish[i] = 0;

	for (int i = 1; i <= v; i++)
		if (finish[i] == 0)dfs(i);
	sort(SCC.begin(),SCC.end());
	cout << SCC.size() << "\n";
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << " ";
		}
		cout << "\n";
	}
}
