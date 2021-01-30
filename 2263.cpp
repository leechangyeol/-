#include <iostream>
#include <vector>
using namespace std;
vector<int> post, in;
const int MAX = 100001;
int inpos[MAX];
int n;
void bfs(int start, int end,int flag) {
	if (start > end)return;
	int mid = inpos[post[end]];
	mid -= flag;
	cout << post[end] << " ";
	bfs(start, mid - 1, flag);
	bfs(mid, end - 1, flag+1);
}
int main(void) {
	cin >> n;
	post = in = vector<int>(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		inpos[in[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	bfs(0, n - 1, 0);

}
