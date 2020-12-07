#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

int n;
vector < pair<int, pair<int, pair<int,int>>>> pose;
vector < pair<int, pair<int, int>>> edge;
vector <int> parent;
vector <int> groupSize;
int findP(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = findP(parent[a]);
}
int nodeUnion(int a, int b) {
	int node1 = findP(a);
	int node2 = findP(b);
	if (node1 == node2) return 0;

	if (node1 < node2) { int temp = node1; node1 = node2; node2 = temp; }
	parent[node2] = node1;
	groupSize[node1] += groupSize[node2];
	groupSize[node2] = 0;
	return 1;
}
int abs(int a) { if (a < 0)return -a; else return a; }
int min(int a, int b, int c) { if (a < b) { if (c < a)return c; else return a; } else { if (c < b)return c; else return b; } }
bool cmpX(pair<int, pair<int, pair<int,int>>> &a, pair<int, pair<int,pair<int, int>>> &b) {
	if (a.first < b.first) return true;
	else return false;
}
bool cmpY(pair<int, pair<int, pair<int, int>>> &a, pair<int, pair<int, pair<int, int>>> &b) {
	if (a.second.first < b.second.first) return true;
	else return false;
}
bool cmpZ(pair<int, pair<int, pair<int, int>>> &a, pair<int, pair<int, pair<int, int>>> &b) {
	if (a.second.second.first < b.second.second.first) return true;
	else return false;
}
int calcDis(int a, int b) {
	return min(abs(pose[a].first - pose[b].first), abs(pose[a].second.first - pose[b].second.first), abs(pose[a].second.second.first - pose[b].second.second.first));
}
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pose.push_back(make_pair(a, make_pair(b,make_pair(c,i))));
	}

	sort(pose.begin(), pose.end(), cmpX);
	for (int i = 1; i < n; i++) {
		edge.push_back(make_pair(calcDis(i, i-1), make_pair(pose[i].second.second.second, pose[i-1].second.second.second)));
	}
	sort(pose.begin(), pose.end(), cmpY);
	for (int i = 1; i < n; i++) {
		edge.push_back(make_pair(calcDis(i, i-1), make_pair(pose[i].second.second.second, pose[i - 1].second.second.second)));
	}
	sort(pose.begin(), pose.end(), cmpZ);
	for (int i = 1; i < n; i++) {
		edge.push_back(make_pair(calcDis(i, i-1), make_pair(pose[i].second.second.second, pose[i - 1].second.second.second)));
	}

	sort(edge.begin(), edge.end());

	parent = vector<int>(n);
	groupSize = vector<int>(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		groupSize[i] = 1;
	}

	int ans = 0;
	for (auto node : edge) {
		if (nodeUnion(node.second.first, node.second.second)) { ans += node.first; }
	}
	cout << ans;

}
