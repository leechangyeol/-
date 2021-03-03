#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50001;
int n;
int p[MAX];
vector<int> ch[MAX];
void make_ch(int node, int value) {
	while (node != 0) {
		ch[node].push_back(value);
		node = p[node];
	}
}
int main(void) {
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		if (a == 1) {
			p[b] = a;
			make_ch(a, b);
		}
		else if (b == 1) {
			p[a] = b;
			make_ch(b, a);
		}
		else if (p[a] == 0) { 
			p[a] = b;
			make_ch(b, a);
		}
		else { 
			p[b] = a;
			make_ch(a, b);
		}
	}
	cin >> n;
	int ans;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ans = b;
		while (1) {

			auto it = find(ch[ans].begin(), ch[ans].end(), a);
			if (it != ch[ans].end() || ans == a)
				break;
			ans = p[ans];
		}
		cout << ans << "\n";
	}
}
