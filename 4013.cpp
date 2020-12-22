#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 500001
using namespace std;

vector<vector<int>> edge, sccEdge;
vector<int> money, sccMoney, discover, sccid;
vector<bool> isres;
stack<int> st;
int n, m;
int s, p;
int nodeN,sccN;
int cash[MAX];
int scc(int here) {
	int ret = discover[here] = nodeN++;
	st.push(here);

	for (auto there : edge[here]) {
		if (discover[there] == -1) ret = min(ret, scc(there));
		else if (sccid[there] == -1) ret = min(ret, discover[there]);
	}

	if (ret == discover[here]) {
		int scm = 0;
		sccN++;
		while (1) {
			int top = st.top();
			st.pop();
			sccid[top] = sccN;
			scm += money[top];
			if (top == here) break;
		}
		sccMoney.push_back(scm);
	}

	return ret;
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	sccN = nodeN = 0;
	
	cin >> n >> m;
	
	sccMoney.push_back(0);
	edge = vector<vector<int>>(n + 1);
	money = vector<int>(n + 1);
	isres = vector<bool>(n + 1,false);
	discover = sccid = vector<int>(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		int a; 
		cin >> a;
		money[i] = a;
	}

	cin >> s >> p;
	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		isres[a] = true;
	}

	for (int i = 1; i <= n; i++) {
		if(discover[i] == -1) scc(i);
	}

	sccEdge = vector<vector<int>>(sccN + 1);
	for (int here = 1; here <= n; here++) {
		for (auto there : edge[here])
			if (sccid[there] != sccid[here]) sccEdge[sccid[here]].push_back(sccid[there]);
	}

	s = sccid[s];
	cash[s] = sccMoney[s];
	for (int i = s; i >= 0; i--) {
		for (auto there : sccEdge[i]) {
			cash[there] = max(cash[there], cash[i] + sccMoney[there]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (isres[i])ans = max(ans,cash[sccid[i]]);
	}
	cout << ans;
}
