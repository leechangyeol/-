#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 10001

using namespace std;

stack<pair<int,pair<int,int>>> pq;
vector<int> minCost;
vector<int> visit;
vector<vector<pair<bool,pair<int, int>>>> material;

int n, m;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	minCost = vector<int>(n + 1);
	material = vector<vector<pair<bool, pair<int, int>>>>(n + 1);
	visit = vector<int>(n + 1,0);
 	for (int i = 1; i <= n; i++) {
		cin >> minCost[i];
	}
	
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		material[b].push_back({ false,{ a,c } });
		material[c].push_back({ false,{ a,b } });
		pq.push({ a,{b,c} });
	}

	while (!pq.empty()) {
		int a = pq.top().first;
		int b = pq.top().second.first;
		int c = pq.top().second.second;

		pq.pop();
		minCost[a] = min(minCost[a], minCost[b] + minCost[c]);
		for (int i = 0; i < material[a].size();i++) {
			if (!material[a][i].first) {
				pq.push({ material[a][i].second.first,{a, material[a][i].second.second} });
				material[a][i].first = true;
			}
		}
	}

	cout << minCost[1];

}
