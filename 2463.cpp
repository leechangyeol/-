#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define MOD 1000000000
using namespace std;

int n, m;
int parent[MAX];
long long setSize[MAX];

vector<pair<int, pair<int, int>>> edge;

int search(int a) {
	if (a == parent[a])return a;
	else return  parent[a] = search(parent[a]);
}

void make_union(int a, int b) {
	
	if (setSize[a] < setSize[b])swap(a, b);

	parent[b] = parent[a];
	setSize[a] += setSize[b];
	setSize[b] = 1;
}

bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
	return a.first > b.first;
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;


	long long sum = 0;
	long long totalCost = 0;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		totalCost += c;
		edge.push_back(make_pair(c, make_pair(a, b)));
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		setSize[i] = 1;
	}

	sort(edge.begin(), edge.end(),cmp);

	for (auto i : edge) {
		int p1 = search(i.second.first);
		int p2 = search(i.second.second);
		int cost = i.first;
		if (p1 != p2) {
			sum += (((setSize[p1] * setSize[p2]) % MOD)*totalCost)%MOD;
			sum %= MOD;
			make_union(p1, p2);
		}
		totalCost -= cost;
	}

	cout << sum;
}
