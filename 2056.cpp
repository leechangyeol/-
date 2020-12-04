#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;
vector <int> working;
vector <int> edge[MAX];
int allocwork[MAX];
int edgeN[MAX];
int n, t;

int main(void) {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		edgeN[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		allocwork[i] = a;
		for (int j = 0; j < b; j++) {
			int c;
			cin >> c;
			edge[c].push_back(i);
			edgeN[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (edgeN[i] == 0)
			working.push_back(i);
	}

	t = 0;
	while (!working.empty()) {
		int addnode = -1;
		int size = working.size();
		for (int i = 0; i < size; i++) {
			if (--allocwork[working[i]] == 0) {
				for (int j = 0; j < edge[working[i]].size(); j++) {
					if (--edgeN[edge[working[i]][j]] == 0) {
						working.push_back(edge[working[i]][j]);
					}
				}
				working.erase(working.begin() + i);
				i--;
				size--;
			}
		}
		t++;
	}
	cout << t;
}
