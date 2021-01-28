#include <iostream>
using namespace std;
const int MAX = 26;
int tree[MAX][2];
int n;
void pre(int node) {
		cout << char(node + 'A');
		if (tree[node][0])pre(tree[node][0]);
		if (tree[node][1])pre(tree[node][1]);
}
void ino(int node) {
	if (tree[node][0])ino(tree[node][0]);
	cout << char(node + 'A');
	if (tree[node][1])ino(tree[node][1]);
}
void pos(int node) {
	if (tree[node][0])pos(tree[node][0]);
	if (tree[node][1])pos(tree[node][1]);
	cout << char(node + 'A');
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.')
			tree[a - 'A'][0] = b - 'A';
		if (c != '.')
			tree[a - 'A'][1] = c - 'A';
	}
	pre(0);
	cout << "\n";
	ino(0);
	cout << "\n";
	pos(0);
}
